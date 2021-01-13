#include <cd50.h>
#include <stdio.h>

int main(void)
{
  int x = get_int("x: ");
  int y = get_int("y: ");

  // Return sum of x and y
  printf("x + y = %i\n", x + y);
}
