#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // TODO: Prompt for start size
  int start = get_int("Start size: ");

  // TODO: Prompt for end size
  int end = get_int("End size: ");

  // TODO: Calculate number of years until we reach threshold
  int llama_stock = start;
  int n = 0;

  while (llama_stock < end)
  {
    llama_stock = llama_stock + llama_stock / 3 - llama_stock / 4;

    n++;
  }

  // TODO: Print number of years
  printf("%i\n", n);
}
