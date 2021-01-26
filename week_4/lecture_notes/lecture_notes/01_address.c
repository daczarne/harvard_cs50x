#include <stdio.h>

int main(void)
{
  int n = 50;
  // Print the variable n
  printf("%i\n", n);

  // Print the address of the variable n
  // We use format type %p to get the Hex value
  printf("%p\n", &n);

  // Go to the address of the variable n, and print the content of that variable
  printf("%i\n", *&n);
}