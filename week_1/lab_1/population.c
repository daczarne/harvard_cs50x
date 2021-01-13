#include <cs50.h>
#include <stdio.h>

// Prototype
int get_int_greater_than(string prompt_message, int number);

int main(void)
{
  // TODO: Prompt for start size
  int start = get_int_greater_than("Start size: ", 9);

  // TODO: Prompt for end size
  int end = get_int_greater_than("End size: ", start);

  // TODO: Calculate number of years until we reach threshold
  int llama_stock = start;
  int n = 0;

  while (llama_stock < end)
  {
    llama_stock = llama_stock + llama_stock / 3 - llama_stock / 4;
    n++;
  }

  // TODO: Print number of years
  printf("Years: %i\n", n);
}

int get_int_greater_than(string prompt_message, int number)
{
  int n;
  do
  {
    n = get_int("%s", prompt_message);
  } while (n < number);
  return n;
}
