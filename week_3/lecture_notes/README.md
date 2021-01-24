# Week 3 - Lecture notes

The computer can not see an entire array. It can only see one location in the array at a time.

## Runnig time

The running time of an algorithm is how long it takes to generate an output. We can measure it in seconds, or steps, or iterations. If an algorithm takes as many steps as it has inputs, then we say that it's an `O(n)` algorithm. If at each step we half the problem, then it's a `O(log n)` algorithm. `O` means *in the order of*.

Generally, we speak of algorithms been:

- `O(n^2)`: number os steps increases with the input size.
- `O(n log n)`
- `O(n)`: as many steps as the input size.
- `O(log n)`: halves the problem at each step.
- `O(1)`: constant number of steps.

Just as the big-O notation describes the upper-bound of an algorithms running time, we use capital omega to describe the lower bound. The bounds are the same as with big-O.

## Search

**Linear search** is checking each element in the array one after the other. This is an `O(n)` algorithm since it requieres 1 step per array index at the worst, and an `Omega(1)` at the best case scenario (if the searched for item is at index 0).

**Binary search** is checking the middle first. Then deciding whether the searched-for item is on the left half or the right half. Descard the half where we know that it can not be. Then repeat with the other half, zeroing in until you find the item. Binary search requiered that the array be sorted. This is a `O(log n)` and `Omega(1)` algorithm.

## Creating data types

Suppose we want to create a data type called `person` that stores the name and his/her's phone number. Both will be stored as strings. To do so we use the following syntax at the top of our code (after the `#include`s):

``` c
typedef struct
{
  string name;
  string number;
}
person;
```

Here `typedef` is just the keyword we use to tell `C` that we are going to be defining a new data type. `struct` is also a keyword and it tells `C` that our data type has a structure. We refer to these as **data structures**. We are just tellinh `C` that this data type has a structure or composition to it.

Next, in between curly braces, we list the components of our data structure, by specifying its data type and name. After that we supply the name of our data structure.

The goal when creating new data structures is to keep related data together. We can refer to the **fields** of a data structure using the dot operator `.` followed by the name of the field. So, suppose that `people` is an array of `person`s, we can access the name of the first person in that array by

``` c
// Intialization
person people[2];
people[0].name = "Brian";
people[0].number = "+1-617-495-1000";
people[1].name = "David";
people[1].number = "+1-949-468-2750";

// Accessing the first person
people[0].name
```

