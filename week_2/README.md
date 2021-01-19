[Functions](#functions)  
[Variables and Scope](#variables-and-scope)  
[Arrays](#arrays)  
[Command-Line Arguments](#command-line-arguments)  

# Functions

As programms get longer and more complex packing all the code inside of `main` will cause your script to be hard to understand. This will have a major impact when it comes to finding bugs. Additionally, you may have to do the same task more than once.

To solve both this issues we use **functions**. In practice, and depending on the context, we might call functions by other names list *procedures*, *methods*, or *subrutines*, but the escence of why we write them is the same.

At the very basic, a function is a piece of code that takes inputs and produces an output. We call the inputs *arguments* and the output *return value*. When we use the function we say that we are *calling* a function.

Since we write functions as independent pieces of code, we can reuse them in our code, or in other programs that we might write latter. We can even pack our functions and share them with other people (this is the goal or packages and modules).

In `C`, the first step of writing a function is to *declare* it. To do so, at the start of our code, we include the function declaration so that the compliter knows that there is going to be a function with that name. Function declaration follow the following standard:

``` c
return_type function_name(arg_list);
```

The *return_type* is the data type for the value that the function will return. *name* is what the function is called. We generally use *snake_case* or *cammelCase* (depending on the language) to name functions. Function names should be verbs or very short frases, evocative of what the function does. Lastly, the *argument_list* is a comma-separated set of inputs that the function takes. Each argument must have a type and a name.

The second step of writing functions is to *define* the function. Defining a function means writting the code of what the function does when it's called in our code. In `C`, we include function definitions at the bottom of our code.

When defining a function we begin the same as with the declaration: `return_type function_name(arg_list)`, but we don't include the semi-colon `;`. Next, starting on a new line, we open include the *body* of our function in between braces. The last line of our function should be a `return` statement followed by the value that our function must return.

``` c
return_type function_name(arg_list)
{
  // Function body
  return value_to_return;
}
```

To use our functions we just need to call them in the body of our `main` code. To do so we use their name and pass to them the requiered arguments of the requiered types. To store the return value of our function we just a variable of the same type as the functions output.

When a function takes no arguments, we declare and define it as taking a `void` argument list. The same is true for outputs. If the function does not have an output then we declare and define it as having a `void` output.

# Variables and Scope


# Arrays


# Command-Line Arguments



