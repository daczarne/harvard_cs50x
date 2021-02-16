# Week 9 - Shorts

[Flask](#flask)  
[AJAX](#ajax)  

## Flask

We can use Python's Flask framework to build a web server that updates the HTML page. To run the app we need to first export the Flask app by running `export FLASK_APP=application.py`. `FLASK_APP` is a system variable that will be stored in memory so that the system knows which application to run if we ever need to run the application again. Then, we can optionally run `export FALSK_DEBUG=1`. In this context, `1` just means `True`. This allows us Flask to print out messages that will be helpfull if we need to debug errors. We only need to run those two commands once. Then, whenever we want to run the app locally, we run `flask run`.

Useful Flask functions

- `url_for()`: allows us to define a function and have a decorator associated with it and then use this function to call it without having to type the entire name.

- `redirect()`: redirects the user to another page

- `session()`: use for HTTP session data

- `render_template()`: render pages built with a template using Jinja

## AJAX


