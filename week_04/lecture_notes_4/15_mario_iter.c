#include <cs50.h>
#include <stdio.h>

darw(int h);

int main(void)
{
  int height = get_int("Height: ");
  draw(height);
}

void darw(int h)
{
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}