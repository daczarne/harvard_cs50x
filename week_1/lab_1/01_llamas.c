#include <cs50.h>
#include <stdio.h>

// Prototype
int get_int_greater_than_nine(void);
int get_int_greater_than_start(int start);

int main(void)
{
  // TODO: Prompt for start size
  int start = get_int_greater_than_nine();

  // TODO: Prompt for end size
  int end = get_int_greater_than_start(start);

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

int get_int_greater_than_nine(void)
{
  int n;
  do
  {
    n = get_int("Start size: ");
  } while (n < 9);
  return n;
}

int get_int_greater_than_start(int start)
{
  int n;
  do
  {
    n = get_int("End size: ");
  } while (n < start);
  return n;
}