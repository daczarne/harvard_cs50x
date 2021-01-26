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

