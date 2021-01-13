#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // Ask user for his/her's name
  string name = get_string("What's your name?\n");

  // Greet the user
  printf("hello, %s\n", name);
}