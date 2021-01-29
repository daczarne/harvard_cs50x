# Week 4 - Shorts

[Pointers](#pointers)  


## Pointers

Pointers provide an alternative way to pass data between function. When we pass data to a function with out using pointers, the data gets passed *by value*. This means that the function receives a copy of the data, not the acctual data.

Pointers are data items whose values are just addresses to locations in memory where other variables live. The type of a pointer describes the data type of the value that is stored in that location.

A special pointer is the `NULL` pointer. This pointer points to nothing. Whenever we create a pointer and don't assign it a value, we should have it point to `NULL`. We can check whether the pointer value is `NULL` using the `==` operator.

A different way of creating a pointer is by extracting the address of a variable that already exists. We can do this by using the *address extraction operator*, `&`. This way, if `x` is an `int` variable, `&x` is a pointer-to-int whose value is the address of `x`. Likewise, if `arr` is an array of `double`s, `&arr[i]` is a pointer-to-double, whose value is the address of the i-th element of `arr`. An array's name, then, is acctually just a pointer to its first element.

The main purpose of a pointer is to allow us to modify or inspect the location of which it points. We do this by **dereferencing** the pointer. To dereference a pointer, we use the `*` operator. If we have a pointer-to-char variable called `pc`, `*pc` is the data that lives at the memory address stored inside the variable `pc`. So what the dereference operator does is to *"go to the reference"* and access the data at that memory location, allowing us to manipulate it. If we try to dereference a `NULL` pointer, we'll suffer a **segmentation fault**.

Pointers are best declared in individual lines. But, if we want to declare multiple pointers (say to `int`s) in the same line, we do so by

``` c
int* pa, *pb, *pc;
```

