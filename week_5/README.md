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

A hash table combines the random access ability of an array with the dynamism of a linked list. With this, insertion, deletion and lookup tends to `Theta(1)` complexity. The cost of this is that they are bad at sorting.

A hash table uses a combination of

- a **hash function**: a function that returns a non-negative value called a **hash code**.

- an array capable of storing data of the type we want to store.

The hash function tells us the position of the array at which we need to store the data point that we want to store. A good hash function should:

- use only the data being hashed

- use all of the data being hashed

- be deterministic

- uniformly distribute data

- generate very different hash codes for very similar data

When two different pieces of data are run through the same hash function are product the same output we have a **collision**. Two store both pieces of data we can use **linear probing**. This means that if there's already another piece of data at the index where the new one should go, we'll place it at the next consecutive element of the array (wrapping around to the beginning if necessitary).

This creates a problem called **clustering** since once that there's a miss, two adjacent cells will contain data, and that makes it more likly that a future element will need to be probed. If this occurs enough times, the data will end up not been sorted at all. Additionally, we are still limited to the length of the array when it comes to storing new data.

We can resolve these issues by using **chaining**. The idea si that instead of placing an element at the index where the hash function told us, we'll place it as the next node of a linked list that starts at that index in the array. This way each position of the array contains a linked list. The element in the array itself is a pointer to the first element of such list.

## Tries



## Data structures


