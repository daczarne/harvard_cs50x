# Week 5 - Lecture Notes

Copying every element of an array to a different memory location is an `O(n)` operation. If there's space available then it's an `Omega(1)` process.

## Data structures

Now we'll use the `struct` keyword, and the `.` and `*` operators to build custom data structures. `.` and `*` operators are so commonly used in this operations that they can be combined into a single operator, `->`

## Linked lists

A linked list is a data structure that solves the problem of having to copy all of the array when having to add a new element for which no memory was allocated. To do this, we use twice as much space. In one block of memory we store the element and in the other block we store the pointer to the next element. The last element has a `NULL` pointer (because it doesn't point anywhere). The first blocks are called **nodes**. We can define it as follows

``` c
typedef struct node
{
  int number;
  struct node *next;
}
node;
```

We can then use `malloc` to generate as many blocks as needed, linking them together by setting the `next` variable to point to the next node with the `->` operator.

The running time of searching a linked list is `O(n)`. This is because a linked list is represented only by a single address: the address that points to the first node. Inserting into a linked list has an `O(1)` running time, because we can insert it at the beginning of the list.
