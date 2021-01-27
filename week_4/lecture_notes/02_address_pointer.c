#include <stdio.h>

int main(void)
{
  int n = 50;
  int *p = &n;

  // Print the address of n
  printf("%p\n", p);
}
