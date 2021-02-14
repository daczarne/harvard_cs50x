# Week 3 - Shorts

[Recursion](#recursion)  

# Recursion

A recursive function is a function that calls itself during the execution time. Every recursive function requiers a **base case**. This is the situation in which the recursion stops. It also requieres a **recursive case**. In this case, the function will call itself but with a smaller problem.

Let's build a factorial function recursively.

``` c
int fact(int n)
{
  // base case (when we get to 1! = 1)
  if (n == 1)
  {
    return 1;
  }
  // recursive case
  else
  {
    return n * fact(n - 1);
  }
}
```

In general, a recursive function can replace a loop in an iterative function (thou not always).

In a recursive function we can have more than one base case. An example of this is the Fibonacci sequence

``` c
int fibonacci(int n)
{
  if (n == 1)
  {
    return 0;
  }
  else if (n == 2)
  {
    return 1;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
```

A recursive function can also have more than one recursive case. An example of this is the Collatz conjecture.

``` c
int collatz(int n)
{
  if (n == 1)
  {
    return 0;
  }
  else if ((n % 2) == 0)
  {
    return 1 + collatz(n / 2);
  }
  else
  {
    return 1 + collatz(3 * n + 1);
  }
}
```
