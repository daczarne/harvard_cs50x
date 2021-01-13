#include <cd50.h>
#include <stdio.h>

int main(void)
{
  // Get inputs
  int x = get_int("x: ");
  int y = get_int("y: ");

  // Compute division
  float z = (float)x / (float)y;

  // Return division of x and y
  printf("z = %f\n", z);
}
