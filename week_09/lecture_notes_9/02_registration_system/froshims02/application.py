# Implements a registration form using a select menu
from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)
