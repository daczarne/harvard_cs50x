#include <cd50.h>
#include <stdio.h>

int main(void)
{
  long x = get_long("x: ");
  long y = get_long("y: ");

  // Return sum of x and y
  printf("x + y = %li\n", x + y);
}
