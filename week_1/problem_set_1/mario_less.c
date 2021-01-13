#include <cs50.h>
#include <stdio.h>

// Prototype
int get_height(void);

int main(void)
{
  // Get height from the user
  int height = get_height();

  // Build pyramid
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (j >= (height - (i + 1)))
      {
        printf("#");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Get height function
int get_height(void)
{
  int n;
  do
  {
    n = get_int("Height: ");
  } while (!(0 < n && n < 9));
  return n;
}
