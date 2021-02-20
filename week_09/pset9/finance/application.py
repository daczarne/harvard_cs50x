import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Get users assets
    assets = db.execute("SELECT asset_symbol, asset_name, asset_qty FROM portfolios WHERE user_id = ?", session["user_id"])
    # Update assets price
    for asset in assets:
        quote = lookup(asset["asset_symbol"])
        asset["price"] = quote["price"]
    # Get users cash
    cash = float(db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"])
    # Calculate total
    total = cash
    for asset in assets:
        total += asset["price"] * asset["asset_qty"]
    # Return page
    return render_template("index.html", assets=assets, cash=cash, total=total, usd=usd)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Get the request parameters
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        # Check empty
        if shares == "":
            return apology("Incomplete form")
        try:
            shares = int(shares)
        except ValueError as ex:
            return apology("Invalid number of shares")
        # Check that shares is non-negative
        if shares < 0:
            return apology("Can only buy a positive amount of shares")
        # Check that shares is integer
        if not isinstance(shares, int):
            return apology("Integer please")
        # Get the quote of the requested symbol
        quote = lookup(symbol)
        # If that stock does not exist, then throw an error
        if quote is None:
            return apology(f"{symbol} does not exist")
        # Check how much cash the user has got left
        cash = float(db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"])
        # Calculate the total cost of the purchase
        total = shares * quote["price"]
        # If the user can do the purchase...
        if total >= cash:
            # Inform the user the he/she is too poor for that
            return apology("Insuficient funds")
        else:
            # Register the transaction
            db.execute(
                "INSERT INTO transactions (user_id, asset_symbol, asset_name, asset_qty, asset_price) VALUES(?, ?, ?, ?, ?)",
                session["user_id"], symbol, quote["name"], shares, quote["price"]
            )
            # Update user portfolio
            rows = db.execute("SELECT * FROM portfolios WHERE user_id = ? AND asset_symbol = ?", session["user_id"], symbol)
            if len(rows) == 0:
                db.execute(
                    "INSERT INTO portfolios (user_id, asset_symbol, asset_name, asset_qty) VALUES(?, ?, ?, ?)",
                    session["user_id"], symbol, quote["name"], shares
                )
            else:
                db.execute(
                    "UPDATE portfolios SET asset_qty = ? WHERE user_id = ? AND asset_symbol = ?",
                    int(rows[0]["asset_qty"]) + shares, session["user_id"], symbol
                )
            # Update user cash
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - total, session["user_id"])
            # Redirect user to index
            return redirect("/")
    # Render the Buy template
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Get the users transactions
    assets = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])
    # Render table
    return render_template("history.html", assets=assets, usd=usd)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)
        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)
        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("Invalid username and/or password", 403)
        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        # Redirect user to home page
        return redirect("/")
    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""
    # Forget any user_id
    session.clear()
    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("That stock does not exist")
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if quote != None:
            return render_template("quote.html", quote=quote, usd=usd)
        else:
            return apology("That stock does not exist")
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # If the user is submitting a form
    if request.method == "POST":
        # Get the form info
        user_name = request.form.get("username")
        password = request.form.get("password")
        confirm_password = request.form.get("confirmation")
        # Check if the user name already exists
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # Check that there acctually is a user_name
        if len(user_name) == 0:
            return apology("Please provide a user name")
        elif len(rows) > 0:
            return apology("User name already exists")
        # Check that password is at least 4 characters long
        elif len(password) < 4:
            return apology("Password must be at least 4 characters long")
        # Check that password and confirm_password are the same
        elif not password == confirm_password:
            return apology("Password dosen't match")
        # If all is ok, hash the password and register the user in the db
        else:
            hashed_password = generate_password_hash(password)
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", user_name, hashed_password)
            # Get the user so that it can be redirected to the homepage
            rows = db.execute("SELECT * FROM users WHERE username = ?", user_name)
            # Remember which user has logged in
            session["user_id"] = rows[0]["id"]
            # Redirect user to home page
            return redirect("/")
    # Else, if the user is visiting the register page
    else:
        return render_template("register.html")


@app.route("/change_password", methods=["GET", "POST"])
def change_password():
    """Change password"""
    # If the user is submitting a form
    if request.method == "POST":
        # Get the form info
        user_name = request.form.get("username")
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirm_new_password = request.form.get("confirm_new_password")
        # Get user info
        user_info = db.execute("SELECT * FROM users WHERE username = ?", user_name)
        # Check that there acctually is a user_name
        if len(user_info) == 0:
            return apology("Invalid user name or password")
        # Check that password is at least 4 characters long
        elif len(new_password) < 4:
            return apology("Password must be at least 4 characters long")
        # Check that password and confirm_password are the same
        elif not new_password == confirm_new_password:
            return apology("Password dosen't match")
        # If all is ok...
        elif not check_password_hash(user_info[0]["hash"], old_password):
            return apology("Invalid username or password")
        else:
            hashed_new_password = generate_password_hash(new_password)
            db.execute("UPDATE users SET hash = ? WHERE username = ?", hashed_new_password, user_name)
            # Remember which user has logged in
            session["user_id"] = user_info[0]["id"]
            # Redirect user to home page
            return redirect("/")
    # Else, if the user is visiting the change password page
    else:
        return render_template("change_password.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Get users list of assets
    assets = db.execute("SELECT asset_symbol FROM portfolios WHERE user_id = ?", session["user_id"])
    if request.method == "POST":
        # Get the request parameters
        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))
        # Get the quote of the requested symbol
        quote = lookup(symbol)
        # If that stock does not exist, then throw an error
        if len(quote) is None:
            return apology(f"{symbol} does not exist")
        price = float(quote["price"])
        # Check how much cash the user has got left
        cash = float(db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"])
        # Check that the user has enough stock to sell
        asset_stock = db.execute(
            "SELECT asset_qty FROM portfolios WHERE user_id = ? AND asset_symbol = ?",
            session["user_id"], symbol
        )
        asset_stock = int(asset_stock[0]["asset_qty"])
        if shares > asset_stock:
            # If the user does not have enough stock, reject the transaction
            return apology("You can't sell an amount higher than what you own")
        else:
            # Calculate the cash from the sale
            sale_income = shares * price
            # Update users cash
            db.execute("UPDATE users SET cash = ? WHERE id = ?", sale_income + cash, session["user_id"])
            # Update users portfolio
            db.execute(
                "UPDATE portfolios SET asset_qty = ? WHERE user_id = ? AND asset_symbol = ?",
                asset_stock - shares, session["user_id"], symbol
            )
            # Register the transaction
            db.execute(
                "INSERT INTO transactions (user_id, asset_symbol, asset_name, asset_qty, asset_price) VALUES(?, ?, ?, ?, ?)",
                session["user_id"], symbol, quote["name"], -1 * shares, price
            )
            # Refirect the user to index
            return redirect("/")
        # Register the transaction
    else:
        print(assets)
        return render_template("sell.html", assets=assets)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
