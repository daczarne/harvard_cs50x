#include <cd50.h>
#include <stdio.h>

// Prototype
int get_positive_int(void);

int main(void)
{
  int i = get_positive_int();
  printf("%i\n", i);
}

int get_positive_int(void)
{
  int n;
  do
  {
    /* code */
    n = get_int("Positive Integer: ");
  } while (n < 1);
  return n;
}