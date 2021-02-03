#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // Assing memory for list
  int *list = malloc(3 * sizeof(int));
  if (list == NULL)
  {
    return 1;
  }

  // Assign elements
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // Allocate a new element
  int *tmp = realloc(list, 4 * sizeof(int));
  if (tmp == NULL)
  {
    free(list);
    return 1;
  }

  // Assign new element
  tmp[3] = 4;

  // Rename list
  list = tmp;

  // Print values
  for (int i = 0; i < 4; i++)
  {
    printf("%i\n", list[i]);
  }

  // Free tmp
  free(list);
}
