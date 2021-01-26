#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string s = "HI!";
  // Print out s
  printf("%s\n", s);
  // Print the string as an address
  printf("%p\n", s);
  // Print the address of the first element of the string
  printf("%p\n", &s[0]);
  // Print the address of the second element of the string
  printf("%p\n", &s[1]);
  // Print the address of the third element of the string
  printf("%p\n", &s[2]);
}
