// Wait for the document to load
// Everything that follows will happen only after the page loads
document.addEventListener('DOMContentLoaded', function() {
  
  // Find the element with the .right class (the correct answer to the question)
  let right = document.querySelector('.right');
  // When the right answer is clicked
  right.addEventListener('click', function() {
    // Change color to green
    right.style.backgroundColor = 'green';
    // Give the user some feedback
    document.querySelector('#response_1').innerHTML = 'That\'s right!';
  });
  
  // Find all wrong answers
  let wrong = document.querySelectorAll('.wrong');
  // If a wrong answer is clicked
  for (let i = 0; i < wrong.length; i++) {
    // Change all of them to red
    wrong[i].addEventListener('click', function() {
      wrong[i].style.backgroundColor = 'red';
      // Give feedback
      document.querySelector('#response_1').innerHTML = 'Nope!';
    });
  }
   
  // Check the open question
  // Listen to the submit button next to the text field
  document.querySelector('#submit').addEventListener('click', function() {
    // Get the answer (text) in the field
    let input = document.querySelector('input');
    // If the text is Brazil or Brazilian Empire then it's correct
    if (input.value == 'Brazil' || input.value == 'Brazilian Empire') {
      // Check the color to green
      input.style.backgroundColor = 'green';
      // let the user know he/she was right
      document.querySelector('#response_2').innerHTML = 'Yeap!';
    } else {
      // Turn it red
      input.style.backgroundColor = 'red';
      // let the user know he/she was wrong
      document.querySelector('#response_2').innerHTML = 'That is not the correct answer!';
    }
  });
});