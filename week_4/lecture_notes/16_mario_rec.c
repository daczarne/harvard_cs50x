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
  if (h == 0)
  {
    return;
  }

  darw(h - 1);

  for (int i = 0; i < h; i++)
  {
    printf("#");
  }
  printf("\n");
}
