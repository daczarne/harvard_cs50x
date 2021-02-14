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

Suppose we want to create a data type called `person` that stores the name and his/her's phone number. Both will be stored as strings. To do so we use the following syntax:

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

## Sorting

**Selection sort** works by selecting the smallest elements over and over, and each time that you find the smallest at that step, you can ignore it. So the number of work decreases by one step at each iteration. In pseudocode this works as follows

```
for i from 0 to n-1
  find the smalles item between the i-th item and the last item
  swap the smallest item with the i-th item
```

This algorithm requieres `n` steps (one per element in the array to be soreted), and at each step we need to compare that element will all remainig elements. So the total number of steps is 

```
n + (n - 1) + (n - 2) + ... + 1 = n(n + 1) / 2
```

thus it's an `O(n^2)` and `Omega(n^2)` algorithm.

**Bubble sort** is an algorithm in which we look at pairs of numbers and sort them. At each step, we only have to look at positions 0 to n-2 of the array. In the first run the largest number will bubble-up to the last position of the array. In the second iteration, the second largest value will bubble-up to the second-to-last position of the array, and so on and so forth. In pseudo code

```
Repeat until sorted
  for i from 0 to n-2
    if i-th and i+1-th elements are out of order
      swap them
  if no swaps where performed
    quit
```

In the worst case, bubble-sort is an `O(n^2)` algorithm. But in the best-case scenario it's an `Omega(n)` algorithm.

## Recursion

**Recursion** is the ability of a function to call itself. In every recursive funtion we must first have a **base case** that tells the function when to stop. We also need to reduce the total size of the input everytime we call it (otherwise it will run forever), this is called the **recursive step**.

**Merge sort** is a recursive sorting algorithm with the following pseudocode

```
if only one number
  quit
else
  sort the left half of numbers
  sort the right half of numbers
  merge sorted halves
```

In this algorithm we need to make use of a **helper function** that defines what does merging mean. In this case, mergin means comparing the first element of two arrays (each of the halfs) and taking the smallest of them.

This algorithm belongs to the family of the **divide and conquer** algorithms in which with each step we split the problem in half. Particularly, in merge sort we are repeating `n` tasks `log n` times, so this is a `O(n log n)` algorithm. But, unlike bubble sort which knew where to stop early (and was thus `Omega(n)`), merge sort is also `Omega(n log n)`.

One problem of recursion is memory usage. For example, in merge sort we need a second array where to put the halves as we sort and merge them, so it requieres twice the memory.

## Theta notation

Everytime an algorithm has the same big-O as its Omega notations, we say that it has a Theta complexity of the same level as its big-O or Omega. So, for example, selection sort is `O(n^2)` and `Omega(n^1)`, so we can say that it's `Theta(n^2)`. 
