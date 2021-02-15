# Week 9 - Flask

We'll use Python's Flask library to do backend (server side) programming. Flask is also a Python framework. One of the things Flask does is URL and request header parsing.

When using the flask framework, we'll organize the files as follows:

- `application.py`: where the code is

- `requirements.txt`: list of requierements (other libs)

- `static/`: static files (CSS, JS, PNGs, GIFs)

- `templates/`: HTML files

Flask uses the following design patter (MVC - Model, View, Controller):

![](flask_dp.png)

The **controller** is where we write the Python code. It can be multiple files. It's the code that controlls (hence the name) how the application works. The **view** is the UI...all that the user sees. The **Model** the service for the data, for example, SQL DB.

To build a Flask app, just statr with

```python
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
  return render_template("index.html")
```

Here, `app = Flask(__name__)` is just telling Flask to turn this code into a web application. So Flask will start listening on the assigned port. `@app.route("/")` sets the route (the URL). The `@` is just a decorator. To start the server, we run in the command line

``` bash
flask run
```

In flas `request.args` is for GET, and `request.form` is for POST.

With Flask, we can factor out common content in HTML files. All these common declarations need to be saved in `templates/layout.html`. This file will look something like this:

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>hello</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

Here, `{% block body %}{% endblock %}` is just Jinja syntax, a special placeholder we use in Flask. The `index.html` file can now be boiled down to only the declarations of what it does (the form in the context of our hello app), and it will look something like this:

``` html
{% extends "layout.html" %}

{% block body %}

    <form action="/greet" method="get">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <input type="submit">
    </form>

{% endblock %}
```

Here `{% extends "layout.html" %}` is just telling Flask that it first needs to include everything that is in the `layout.html` file. Then, everything that needs to be placed inside the placeholder that we set in `layout.html`, needs to be declared in this file between `{% block body %}` and `{% endblock %}`, and Flask will take care of parsing everything as needed.

## Sessions

A session is a crucial part of modern web dev. It's what allows the server to remember that a user who has authenticated, is still loged in. Let's that the example of gmail. Everytime we visit, the browser sends a request like this

``` txt
GET / HTTP/1.1
Host: gmail.com
```

and the server response might be something like follows

``` txt
HTTP/1.1 200 OK
Content-Type: text/html
Set-Cookie: session=value
```

Cookies are pieces of data or files that are placed on the device by a server that help the server remember that the user has been there before. These files usually just contain a large random value that uniquely identifies the user. So in the example reposonse, the `Set-Cookie` header takes a value of `session=value` where `session` is the name of the cookie and `value` is the user's identifier. After that, the browser will send back the cookie to the server with every request. So, after login, every request will look as follows

``` txt
GET / HTTP/1.1
Host: gmail.com
Cookie: session=value
```
