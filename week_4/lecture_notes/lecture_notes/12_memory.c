#include <stdio.h>
#include <stlib.h>

int main(void)
{
  char *s = malloc(3);
  s[0] = 'H';
  s[1] = 'I';
  s[2] = '!';
  s[3] = '\0';
  printf("%s\n", s);
}