# Week 4 - Lecture Notes

## Hexadeimal

We'll count in a base-16 system called **Hexadecimal**. It's digits are 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F. Hexadecimal is good for representing groups of 4 bits. When expresing numbers is Hex we prefix them with `0x`. So, for example, `72` is `0x48`, `73` is `0x49`, `33` is `0x21` and so on. We use Hex to name the memory addresses in the computer. 

## Address operators

`&`: is the **address of operator**. If we prefix a variable with an ampersand `C` will tell us in which memory address the variable is stored.

`*`: is the **dereference operator**. If we prefix a vairable with the star `C` will look in that address.

So `&` figures out what the address is, and `*` goes to that address. This are reverse operations, so we can use `*&<reference>` to get the value of that reference.

## Pointers

A **pointer** is a variable that store the address of some other variable, of any type. To declare a pointer we use

``` c
int n = 60;
int *p = &n;
```

Here we are giving `p` a type of `int` because it's a pointer to a variable of type `int`. In programming jargon we say that `p` is of type *int star*.

Pointer are variables themselves. So they take up memory (8 bytes) and also have an address.

We can now start thinking of a string as the address of the first element (the first `char`) of the string. `C` will know where to end because the end of a string is always `\0`. In fact, `string`s don't really exist in `C` as a datatype, they are `char *` variables.

``` c
char *s = "HI!;
```

We can implement this by way of

``` c
typedef char *string;
```

## Pointer arithmetic

We can do simple math on pointers.

``` c
char *s = "HI!";
// Print the first letter
printf("%c\n", *s);
// Print the second letter
printf("%c\n", *(s + 1));
// Print the third letter
printf("%c\n", *(s + 2));
```

We can assign the same address to multiple pointers

```c 
char *s = get_string("s: ");
char *t = s;
```

 But if we now modify either of them, the other one will be modified too since it's pointing to the same value. We can copy a string by asking the computer to give us some extra memory where to store the copy. To do so we use the `malloc` function from the `stdlib` header. `malloc` stands for **memory allocation**. Its input is just the number of bytes that the computer should reserve (allocate) for the new variable. We then need to loop over the orignal string and save it in the new variable.

``` c
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1);

for (int i = 0, n = strlen(s); i <= n; i++)
{
  t[i] = s[i];
}
```

`NULL` is the absence of an address (technically, address zero). We use `NULL` in the context of pointers. Not to be confused with `'\0'` the `NULL` char.

We can also use the function `strcpy(t, s)` to copy the string `s` into the string `t`.

When using `malloc` we need to then use the function `free` to release the memory and give it back to the OS for other operations.

To chase bugs on memory we use `valgrind`. A debbuger for memory. We run it in the command line with `valgrind ./<program>`.

## Garbage

Stuff in memory just lays around. The computer doesn't initialize variables for you unless you specifically tell it to place a certain value in a variable. So if we declare a variable, and don't assign a value to it, then the computer will point to whatever value is there already. This value might be result of a previous computation that we did in this program or in another one. We refer to these values as **garbage values**.

The only exception to this no-declare-on-init rule is for global variables. Global variables are initialized to zero or `NULL`.

## Swapping values

To swap two variables we need to understand how the CPU uses memory. The first chunk of memory(think of it as top part of the physical hardware) is used for machine code. This is were the programs are run.

After that comes all the global variables. Next comes the `heap`. This is a big chunk of memory that malloc uses to get you some spare memory.

Last comes the `stack`. The stack starts at the *"bottom"* and starts filling in values to the top. The stack space is what functions use to run.

![](memory.png)

## heap overflow & stack overflow

A **stack overflow** is what happens when a function gets called so many times, that it overflows the heap. If this happens, the program will crush. The opposite is called a **heap overflow**.

## buffer overflow

A buffer is a chunck of memory. A **buffer overflow** is what happens when we go beyond that amount (for example, iterating past the end of an array).

## `scanf`

We use the function `scanf` to get input from the user. When we want to get string input memory allocation becomes a problem, because we don't know who long a string the user will input.

If the `char` is declared using `malloc` the memory comes from a frame on the `head`. When using `malloc` we need to remember to then use `free` to release the memory allocated.

``` c
char s = malloc(4);
```

If instead, the `char` is declared using an array bracket notation, the memory comes from a fram on the `stack`.

``` c
char s[4];
```

Not that we don't need to use `char *s` because `s` is already a memory address.

## Files

We can read and write data to files using the `fileio.h` library. To declare a pointer to a file we use the `FILE` data type.

To open the file we use the `fopen` function. This function takes two values, the name of the file (including its extension) and an opening  mode: "r" for read, "w" for write, and "a" for appending. 

Once we open the file, we can write new data to it using the `fprintf` function. When done working with the file we need to call `fclose(file)`, where `file` is the pointer to the file we where using.

