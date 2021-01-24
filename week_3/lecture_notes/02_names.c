#include <stdio.h>
#include <cd50.h>
#include <string.h>

int main(void)
{
  // Sorted array
  string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

  // Linear search
  for (int i = 0; i < 7; i++)
  {
    if (strcmp(names[i], "Ron") == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
