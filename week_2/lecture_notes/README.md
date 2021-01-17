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

