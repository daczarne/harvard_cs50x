#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

int main(void)
{

  int scores[TOTAL];
  for (int = 0; i < TOTAL; i++)
  {
    scores[i] = get_int("Score: ");
  }

  printf("Avg: %f\n", (scores[0] + scores[1] + scores[2]) / TOTAL);
}