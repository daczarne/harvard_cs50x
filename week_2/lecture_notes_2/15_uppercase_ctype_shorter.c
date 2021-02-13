#include <cd50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Prompt the user for input
  string s = get_string("Before: ");
  printf("After: ");

  // Print characters in uppercase
  for (int = 0, n = strlen(s); i < n; i++)
  {
    printf("%c", toupper(s[i]));
  }

  printf("\n");
}
