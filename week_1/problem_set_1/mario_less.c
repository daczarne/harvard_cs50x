#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Get height from the user
  int height = get_int("Height: ");

  // Build pyramid
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}
