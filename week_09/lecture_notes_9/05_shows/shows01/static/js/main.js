// Accesses the input tag on the web page
let input = document.querySelector('input');
input.addEventListener('keyup', function() {
  // AJAX call - the ability of a webpage to make additional requests to the server
  $.get('/search?q=' + input.value, function(shows) {
    // Then render
    let html = '';
    for (let id in shows) {
      let title = shows[id].title;
      html += '<li>' + title + '</li>';
    }
    document.querySelector('ul').innerHTML = html;
  })
});
