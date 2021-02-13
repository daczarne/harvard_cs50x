# Week 1 - Lecture Notes

`.c` files are source code files for C.

`.h` files are header files (like libraries in Python or R).

After we finish writting our *source code*, we run `make file_name` in the terminal and the complier will complie our code into *machine code* that the CPU can work with. To run our program we run `./file_name` in the terminal.

## C data types

Each data types uses a specific number of bits to be stored.

- **string**: character string values. Declare with double quotes `"`.

- **char**: single character values. Declare with single quotes `'`.

- **bool**: booleans

- **float**: real numbers (single precision point)

- **double**: real numbers (multiple precision points)

- **int**: integers (32 bits)

- **long**: integers (64 bits)

In C we can use type casting. Suppose `x` is an **int** and we need it as a **float**, so we type `(float)x`.

## printf formats

- `%c`: placeholder for single **char**acter

- `%f`: placeholder for a **float**ing point value. Can add precision values with `%.10f` will return the number with 10 decimal places.

- `%i`: placheholder for an **integer** value

- `%li`: placeholder for a **long** value

- `%s`: placeholder for a **string** value

## C operators

- `+`: addition

- `-`: substraction

- `*`: multiplication

- `/`: division

- `%`: remainder

## Syntactic Sugar

`x = x + 1` can be written as `x += 1` and is the same as `x++`.

## Conditions

### `if` statement

``` c
if (x < y)
{
  printf("x is less than y\n");
}
```

### `else` statement

``` c
if (x < y)
{
  printf("x is less than y\n");
}
else
{
  printf("x is not less that y\n");
}
```

### `else if` statement

``` c
if (x < y)
{
  printf("x is less than y\n");
}
else if (x > y)
{
  printf("x is greater that y\n");
}
else
{
  printf("x is equal to y\n");
}
```

## Loops

### While loops

While loops take a condition. The body of the loop is executed over and over again as long the condition is `true`.

``` c
while (true)
{
  printf("hello, world\n");
}
```

Counter variables are `i` for integers, `c` for characters, or `s` for string. Don't start counters on 1. 

``` c
int i = 0;
while (i < 50)
{
  printf("hello, world\n");
  i++;
}
```

``` c
int i = 50;
while (i > 0)
{
  printf("hello, world\n");
  i--;
}
```

### For loop

First, initialize a counter to some value. Then, add the condition. Lastly, include an update for the counter. Separate them wiht semi-colon `;`.

``` c
for (int i = 0; i < 50; i++)
{
  printf("hello, world\n");
}
```

## Abstraction

When defining functions in C, include a prototype at the top and the function definition at the bottom.

```c
// Prototype
void meow(void);

// More program

// Function
void meow(void)
{
  printf("meow\n");
}
```

This function only has a side-effect, it doesn't have a return value (that's why we use `void`). The same applies to the function inputs, since there are none, we use `void`.

If we want the funtion to take an input parameter, we define the input type and the input name.

```c
// Prototype
void meow(void);

// More program

// Function
void meow(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("meow\n");
  }
}
```

If we want our function to have an output, we preceed the function declaration with the output's data type.

``` c
int get_positive_int(void)
{
  int n;
  do
  {
    /* code */
    n = get_int("Positive Integer: ");
  } while (n < 1);
  return n;
}
```

Here the `do while` loop is going to executre the `do` clause before each iteration of the `while` loop. So the loop will continue asking the user for an positive integer value, until the user indeed inputs one. After that, it will return the value that the user inputed.
