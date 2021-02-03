# Week 5 Shorts

[Singly-linked lists](#singly-linked-lists)  
[Hash tables](#hash-tables)  
[Tries](#tries)  
[Data structures](#data-structures)  

## Singly-linked lists

So far, when we've needed to put together collections of values of the same type we've used an array. When we needed to make collections of values of different classes we used `struct`s.

We can build new data structures that allow for adding and removing elements in any part of it. This data structure is called a **singly-linked list**. These lists are compraised of **nodes**. Each node is a collection (a `struct`) of two fileds: a value and a pointer to the next node. We can declare them as follows

``` c
typedef struct sllist
{
  VALUE val;
  struct sllist* next;
}
sllnode;
```

where by `VALUE` we just refer to any data type for the value (`int`, `char`, `float`, etc). Since this is a *self-referential data type* we first need to give it an alias (in this case `sllist`) so that we can tell the compiler how to self-refere one item to another (by way of the `next` pointer). The data type declared is called `sllnode`.

When using linked lists we always need to keep track of the `head` (the pointer to the first element). We might even want to put this pointer in a global variable.

## Hash tables


## Tries


## Data structures


