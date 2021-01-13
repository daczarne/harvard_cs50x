#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string answer = get_string("What's you name?");
  // Greet the user
  printf("hello, %s", answer);
}
