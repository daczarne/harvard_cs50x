# Week 4 - Shorts

[Pointers](#pointers)  
[Custom data types](#custom-data-types)  
[Dynamic memory allocation](#dynamic-memory-allocation)  
[Call stacks](#call-stacks)  
[File pointers](#file-pointers)  

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

## Custom data types

With the `typedef` keyword we can define new data types or rewrite names for data types. To do se, we define a type in the normal way, and then alias it to something else.

``` c
typedef <old_name> <new_name>;
```

For example, we can use

``` c
typedef char* string;
```

We can also use the `struct` data type to define new complex data types. For example,

``` c
typedef struct car
{
  int year;
  char model[10];
  char plate[7];
  int odometer;
  double engine_size;
}
car_t;
```

## Dynamic memory allocation

We can use pointers to get access to a block of dynamically-allocated memory at runtime. This memory comes from a pool of memory called the `heap` (unlike function calls which are executed in a pool of memory called `stack`).

To get memory at runtime we use the `malloc` function (*memory allocator*). This function takes as a parameter the number of bytes that we are requesting. It will return a pointer to the memory location that it has assigned. If, for some reason, `malloc` can't allocate memory, it will return `NULL`. This is way, after every `malloc` call, we need to check whether the return value was `NULL`. If it was, then we need to terminate the program (it's going to crush anyway if we don't terminate it).

``` c
// statically obtain an integer
int x;
// dunamically obtain an integer
int *px = malloc(sizeof(int));
```

Unlike statically-allocated memory, dynamically-allocated memory is not automatically returned to the system for later use when the function in which it's created finishes execution. We need to explicitly free the memory by calling the `free()` function and pass it the name of the pointer to free-up as an argument. Failing to free the memory results in a **memory leak**.

Do not `free` statically-allocated memory, and only `free` dynamically-allocated memory once!!

As an exmaple

``` c
// Create an integer variable called m in the stack.
int m;
// Create a pointer called a to an integer. The pointer is in the stack.
int* a;
// Create a pointer called b to an integer. 
// Here we've allocated two chunks of memory. One for the pointer and one for the variable it points to.
// The vairable (which does not have a name) is on the heap.
// But the pointer b is on the stack.
int* b = malloc(sizeof(int));
```

![](./dynamically_allocated_memory_1.png)

``` c
// a gets m's address
// This means that a now points to m
a = &m;
```

![](./dynamically_allocated_memory_2.png)

``` c
// Changes where a is pointing too (the address it holds)
// a now points to where b points (since b is a pointer itself)
// This is not to be confused with a pointing to b. To do that we use a = &b
a = b;
```

![](./dynamically_allocated_memory_3.png)

``` c
// Set the value of m to be 10
m = 10;
// Dereference b (*b) with the value of m + 2.
// This means that we are setting the unnamed variable to which b is pointing to, to be 12 (m + 2)
*b = m + 2;
```

![](./dynamically_allocated_memory_4.png)

``` c
// Release the memory used by the variable to which the pointer b points to
free(b);
```

![](./dynamically_allocated_memory_5.png)

``` c
// This would cause the variable to which a is pointing to be dereferenced with the value 11.
// But since we've free'd up that memory, it will cause a segmentation fault
*a = 11;
```

## Call stacks

When we call a function a chunk of memory is assigned for that function to do its necessary work. We call these chunks of memory **stack frames** or **function frames**. If it possible that more than one stack frame exists at any given time. This happens when we have functions (such as `main`) that call other functions. Yet, only the frame of the function that is running is active at any given time. These frames are arranged in a stack with the most recently called function at the top of the stack. When a new function is called, a new frame is **pushed** onto the top of the stack and becomes the new active frame. When a function finishes its work, the frame is **popped** off of the stack and the frame immediatly below becomes the active frame and continus its execution from where it left off.

## File pointers

File pointers and (variable) pointers are inter-related, but are not the same. The ability to read from and write to files is the primary means of stofing *persistent data*. To manage files is in `C` we use a data structure called `FILE`. When working with files we will almost always be using pointers to them, `FILE*`.

The main file-manipulation in `C` can all be found in `stdio.h`. They all take a file pointer, `FILE*` as an argument, except `fopen` which is the function we use to get a pointer. The most important functions are...

### `fopen`

We use it to open a connection to a file, and it returns a pointer to the file that can be used in other function calls. Because its return value is a pointer we must always check that it is not `NULL`. We invoke `fopen` by

``` c
FILE* ptr = fopen(<file_name.ext>, <operation>);
```

where `FILE*` is the aforementioned file pointer, `ptr` is a generic name for a file, `<file_name.ext>` is the name of the file including its extension, and `<operation>` is what we want to do with that file. We use `r` for *read operations*, `a` for *append operations*, `w` is for *writing operations*. The difference between write and append is that the former overwrites the entire file while the latter adds new lines to the file.

### `fclose`

This function takes a `FILE*` pointer as an argument and closes the connection to it. WE use it as follows.

``` c
fclose(<file_pointer>);
```

Once a file is closed, we can't perfom any other I/O operations on that file (unless we open it again).

### ``fgetc`

We use this function to get the next `char` from the file pointed to. During the first call, it will return the first character. To do so, the file must have been opened with an `r` operation. We use this function as

``` c
char ch = fgetc(<file_pointer>);
```

To read every single `char` in a file we must use a loop.

``` c
char ch;
while ((ch = fgetc(<file_pointer>)) != EOF)
{
  printf("%c", ch);
}
```

`EOF` is a special character defined in `stdio.h` that signifies the **end of file** character. This is basically what the command-line command `cat` does.

### `fputc`

This function allows us to wrtie a single `char` to the pointed-to file. The operation of the file pointer must we either `w` or `a`. We use this function as follows:

``` c
fput(<character>, <file_pointer>);
``` 

We can replicate the command-line command `cp` as follows:

``` c
char ch;
while ((ch = fgetc(<file_pointer_to_copy_from>)) != EOF)
{
  fputc(ch, <file_pointer_to_copy_to>);
}
```

### `fread`

This is a generic version of `fgetc` that allows us to get any amount of information. We use it like so:

``` c
fread(<buffer>, <size>, <qty>, <file_pointer>);
```

This will read `<qty>` units of size `<size>` from the file pointed to by `<file_pointer>` and store it in memory in a buffer (usually an array) pointed-to by `<buffer>`. The file-pointer operation must be `r`.

As an example

``` c
int arr[10];
fread(arr, sizeof(int), 10, ptr);
```

Here we are creating an array called `arr` of lenght 10 and class `int` in the stack (this is our buffer). Then we will read `sizeof(int) * 10 = 40` bytes of information from a file pointed to by `ptr`, and store each one of those 10 chunks of information in `arr`, in the same order as the were read.

We could also save our buffer in the heap by using dynamic-memory allocation like follows:

``` c
double* arr = malloc(sizeof(double) * 80);
fread(arr, sizeof(double), 80, ptr);
```

Lastly, we could also treat `fread` as a call to `fgetc`. To do so we use

``` c
char c;
fread(&c, sizeof(char), 1, ptr);
```

In the previous two examples we were using arrays. Arrays are just pointers to the first element in them, so this was OK for the `<buffer>` in `fread`. But now, we need to pass not the declared variables, but rather the address of the declared variable so that `fread` can write to that address in memory. So we use `&c`.

### `fwrite`

This is the writing vertion of `fread`. We use it like so

``` c
fwrite(<buffer>, <size>, <qty>, <file_pointer>);
```

The only thing to keep in mind here is that the pointer needs to be a `w` or `a` operation.

### Other functions for files

Other functions is `stdio.h` for working with files are

- `fgets` and `fputs` are the same as `fgetc` and `fputc` but for entire strings.

- `fprintf` writes a formated string to a file.

- `fseek` allows to rewind or fast-forward within a file

- `ftell` tells you at what byte position you are at within a file

- `feof` tells you whether you've read to the endo of a file

- `ferror` indicates whether an error has occurred in working with a file.
