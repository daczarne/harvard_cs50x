# Implements a registration form using radio buttons

from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

REGISTRANTS = {}


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("failure.html")
    sport = request.form.get("sport")
    if not sport:
        return render_template("failure.html")
    if sport not in SPORTS:
        return render_template("failure.html")
    # Confirm registration
    return render_template("success.html")