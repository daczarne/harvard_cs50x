#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(void)
{
  // Initialize an empty linked list with a NULL pointer
  node *list = NULL;

  // Allocate a node
  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }

  // Populate the fields
  n->number = 1;
  n->next = NULL;

  // Link the list to the first value
  list = n;

  // Allocate a node
  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list);
    return 1;
  }

  // Populate the fields
  n->number = 2;
  n->next = NULL;
  list->next = n;

  // Allocate a node
  n = malloc(sizeof(node));
  if (n == NULL)
  {
    free(list->next);
    free(list);
    return 1;
  }

  // Populate the fields
  n->number = 3;
  n->next = NULL;
  list->next->next = n;

  // Print the linked list with a loop that reads like follows
  // node *tmp = list: gives me a temporary pointer to a node called tmp
  // and initialize it to be whatever is at the beginning of the list.
  // tmp != NULL: keep executing the body of the loop so long as tmp is not null
  // tmp = tmp->next: after each iteration, update the tmp pointer  to be whatever
  // the value of the tmp->next is
  for (node *tmp = list; tmp != NULL; tmp = tmp->next)
  {
    // Print whatever value is in the number field of that tmp
    printf("%i\n", tmp->number);
  }

  // Free list: read like this
  // while the list is not null (aka freed)
  while (list != NULL)
  {
    // Get a tmp pointer
    node *tmp = list->next;

    // Free the list node
    free(list);

    // Update list to be tmp
    list = tmp;
  }
}
