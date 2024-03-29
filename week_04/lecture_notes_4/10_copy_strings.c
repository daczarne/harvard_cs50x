#include <stdio.h>
#include <cd50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
  char *s = get_string("s: ");
  char *t = malloc(strlen(s) + 1);
  if (t == NULL)
  {
    return 1;
  }

  for (int i = 0, n = strlen(s); i <= n; i++)
  {
    t[i] = s[i];
    // This is equivalent to
    // *(t + i) = *(s + i);
  }

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
    // This is equivalent to
    // *t = toupper(*t);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);
}
