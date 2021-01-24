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

