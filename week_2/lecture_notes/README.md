# Week 2 - Lecture Notes

## Command Line Arguments

When we call `make hello` on the terminal, we are actually calling a more complex command to give the computer an instruction of how to complie our code. `clang` is the compiler we are using. If we just run `clang hello.c` we'll get an output called `a.out` which stands for *Assembly output*.

If we want to specify a name for the output file we use

``` bash
clang -o hello hello.c
```

The `-o` flag stands for *output* and is used to tell `clang` what the output file should be named. After it we supply the name for the output and lastly, the `C` script to compile.

The second program we wrote last week included prompting the user for input using the `get_string` function from the `cs50` library. If we run `clang -o hello hello.c` on that script, we'll get an error. This is because when including a library, it is not sufficient to just `#include` it at the top of the script. This happens because we need to tell `clang` where to find the functions that are included in a header file (in this case `cs50.h`).

``` bash
clang -o hello hello.c -lcs50
```

To include the binary code from another library we use the `-l` argument (which stands for *link*).

## Compiling

So, it turns out that when we talk about *compiling* our code, we are acctually talking about four different steps.

- preprocessing  
- compiling  
- assembling  
- linking  

In the **preprocessing** step what `clang` will do is to replace the `#include <stdio.h>` and `#include <cs50.h>` header files for the function prototypes that are included in those files. 

After that comes the actual **compiling**. In this step, `clang` will convert our source code into a different type of source code called *Assembly code*. This is the language in which CPUs are programmed.

Next, in the **assembling** step, `clang` will create the actualy machine code (1s and 0s) that the hardware can understand.

Finally, the **linking** step includes bringing into your assembled code (the 0s and 1s), the assembled code from all the libraries that you are using.

## Debugging

*Debugging* is the term used to finding mistakes in code. Sometimes these mistakes will cause our code not to complie, but other times, they will be problems with the logic of our program (by this we mean that the program runs fine, but it dosen't do what we expected it to do).

One way of debugging logical errors is to use the `printf` function. Since code is executed top to bottom, we can include `printf` calls in our code to see what the value of a variable is at that stage in the execution.

Other more sophisticated tools for debugging are called **debuggers**. These are programs that every languge has that allow us to run the program step by step and peak into the execution process.

When using debuggers, we need to set *breakpoint* in our code so that the execution stops at that point and we can inspect the state of our program before continuing.

## Arrays

An array is a squence of values stored in memory. Think of it a list of values. We decalre an awway in `C` as follows

``` c
int scores[3];
```

With this `C` will build an array of integer three values, and it will call that array `scores`. To assign values to the array, we use

``` c
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;
```

Notice that `C` uses 0-indexing.

---
Side note

We use the qualyfier `const` to declare a variable as a constant varaible. That means that that variable cannot be changes through out the execution of our program. If we try to change it, we'll get an error.

``` c
const int TOTAL = 10;
```

By convention, when using constants, we capitalize them.

---

To pass an array into a function, we need to tell the function that the argument is an array by using the `array[]` in its list of argument

``` c
float average(int length, int array[])
{
  float sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / length;
}
```
