#include <stdio.h>

int main(void)
{
  char *s = "HI!";
  // Print the first letter
  printf("%c\n", *s);
  // Print the second letter
  printf("%c\n", *(s + 1));
  // Print the third letter
  printf("%c\n", *(s + 2));
}
