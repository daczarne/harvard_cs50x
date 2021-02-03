#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  // Initialize a list with a NULL pointer
  node *list = NULL;

  // Allocate memory for a new element
  node *n = malloc(sizeof(node));

  // Assign the value and pointer
  if (n != NULL)
  {
    n->number = 1;
    n->next = NULL;
  }

  // Link the list to the first value
  list = n;

  // Allocate memory for a new element
  node *n = malloc(sizeof(node));

  // Assign the value and pointer
  if (n != NULL)
  {
    n->number = 2;
    n->next = NULL;
  }

  // Link new element to the list
  list->next = n;

  // Allocate memory for a new element
  node *n = malloc(sizeof(node));

  // Assign the value and pointer
  if (n != NULL)
  {
    n->number = 3;
    n->next = NULL;
  }

  // Link new element to the list
  list->next->next = n;

  // Free the malloced menory
  free(n);
}
