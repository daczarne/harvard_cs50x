from flask import Flask, redirect, render_template, request, session
from werkzeug.wrappers import CommonRequestDescriptorsMixin
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure sessions
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"  # the hard drive
Session(app)


@app.route("/")
def index():
    if not session.get("name"):
        return render_template("login.html")
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        # Rememebr that user logged in
        session["name"] = request.form.get("name")
        # Redirect the user to /
        return redirect("/")
    return render_template("login.html")
