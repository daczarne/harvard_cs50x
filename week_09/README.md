# Week 9 - Shorts

[Flask](#flask)  
[AJAX](#ajax)  

## Flask

We can use Python's Flask framework to build a web server that updates the HTML page. To run the app we need to first export the Flask app by running `export FLASK_APP=application.py`. `FLASK_APP` is a system variable that will be stored in memory so that the system knows which application to run if we ever need to run the application again. Then, we can optionally run `export FALSK_DEBUG=1`. In this context, `1` just means `True`. This allows us Flask to print out messages that will be helpful if we need to debug errors. We only need to run those two commands once. Then, whenever we want to run the app locally, we run `flask run`.

Useful Flask functions

- `url_for()`: allows us to define a function and have a decorator associated with it and then use this function to call it without having to type the entire name.

- `redirect()`: redirects the user to another page

- `session()`: use for HTTP session data

- `render_template()`: render pages built with a template using Jinja

## AJAX

**AJAX** allows us to dynamically update a webpage without having to re-render it completely as it would when calling the server. To use AJAX we need to use a special object called an `XMLHttpRequest` that will allow us to make asynchronous requests to a server. Here *asynchronous* just means that we are not going to be fulfilling the request when the client-side calls the server-side (that would require updating the entire page) but in between those calls (whenever that may happen). This is usually used to update small parts of the page. To create one such request we just use

``` js
let xhttp = new XMLHttpRequest();
``` 

Once we have the object, we need to define its `onreadystatechage` behavior. This is a function that will be called when the asynchronous HTTP request has completed, and thus typically defines what is expected to change on the site. We usually use an anonymous function to handle this.

`XMLHttpRequest`s have two additional properties that are used to detect when the page finishes loading. The `readyState` property will change from 0 (request not yet initialized) to 1, 2, 3, and finally 4 when the request finishes and the response is ready. If everything when OK, the `status` property will be 200 (OK). When this is completed, we use the `open()` method to define the request and the `send()` method to send it. All of this is generally done using `jQuery`.

``` js
function ajax_request(argument)
{
  // Create the request
  let aj = new XMLHttpRequest();
  // This function will execute every time the state changes, but will only acctually do
  // anything when the readyState is 4 and the status 200
  aj.onreadystatechange = function() {
    if (aj.readyState == 4 && aj.status == 200) {
      // do something
    }
  };
  // Open the GET request to the URL
  aj.open("GET", /* url */, true);
  // Send the request
  aj.send()
}
```
