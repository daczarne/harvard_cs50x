# Week 2 - Shorts

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

Scope is a characteristic of a variable that determines from which functions that variable can be accessed. Variables can have a *local* scope, or a *global* scope.

Local variables can only be accessed withing the functions in which they are created. They are defined inside the function in which they are used.

Gobal variables can be accessed by any function in the program. They are created outside the functions (in the main program).

# Arrays

Arrays are collections of values of the same data type that we can refer to with one name. Each member of that collection is called an *element*. Each element of the array can be accessed by its *index* number. Index numbers are sequential, integers, starting from 0.

We need to keep in mind that `C` by itself will not prevent us from going out of bounds. Since the arrays are stored sequentially on memory, if we try accessing an index greater than *n-1*, at run time, `C` will return whatever is there.

To declare an array we use

``` c
type name[size];
```

where *type* is the data type that all elements in the array will have, *name* is the reference to that array, and *size* is the number of elemnts that we want the array to hold.

To assign values to the elements of an array we use

``` c
name[index] = value;
```

where *name* is the name of the array, *value* is the value to be assigned, and *index* is the position to which we want to assign that value.

To initialize an array (that is, declare and assign in one step), we use

``` c
type name[size] = {v1, v2, ..., vn};
```

Elements will be assign in order, so the first value to the 0-index, the second value to the 1-index, and so on until the nth value is assigned to n-1 index. When we list the elements this way, we can omit the *size* and the compiler will still know what to do.

Array elements can be of any data type, including other arrays. To access elements of an array that is inside another array we use two pairs of square brakets. So for instance,

``` c
array_name[index_i][index_j]
```

will return the j-th element of the i-th array in `array_name`. In memory though, this is just one array of length *i x j*.

We can not assign one array to another array.

# Command-Line Arguments

To pass command line arguments into the program we change the input of main to be

``` c
int main(int argc, string argv[])
{
  // Program body
}
```

Here *argc* is the number of command-line arguments, and *argv[]* is a string array of the different command line arguments. *argv[0]* is always the name of the program.
