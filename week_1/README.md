# Week 1 Shorts

[Data types](#data-types)  
[Operators](#operators)  
[Conditional statements](#conditional-statements)  
[Loops](#loops)  
[Command Line](#command-line)  

# Data types

In `C` we need to specify the data type of each variable every time we define them. `C` will "use" them differently depending on the data type. By this we mean that, for example, the sum of, say, two integer numbers my look the same regardless of whether the variables are declared as `int`s or `float`s, but under the hood `C` is working differently with them.

## Integer numbers

Variables of type `int` can only store integers. This are whole numbers (both snegative and positive). Integers always take up 4 bytes of memory (32 bits). So the their values will range from -2<sup>31</sup> to 2<sup>31</sup>-1 (because 0 takes up one spot).

Variables of type `int` can take *qualifiers*. One of such is **unsigned**. This qualifier doubles the positive range of variables, but it disallows negative values. This makes the range of `unsigned int`s go from 0 to 2<sup>32</sup>-1

## Characters

Variables of type `char` take up one single character value. They always take up one byte of memory (8 bits). This means that `char`s can only take up values from -128 to 127. We use the ASCII table to map those numeric values to their corresponding character values. So, for example, character `A` is 65, `a` is 97, `0` is 48.

## Real numbers

To store real numbers we use variables of type `float`. These take up 4 bytes (32 bits) of memory to be stored. Unlike the actual real number line in math, computers have a *precision* limitation (since we can only represent that many digits after the decimal point), which implies that for computers the "real number line" is not dense. 

To partialy solve this problem we can use variables of type `double`. This means that these variables will have twice the precision (hench double). But they also take up twice the memory space (8 bytes per value or 64 bits).

## `void`

Unlike `char` or `int` or `float`, `void` is not a data type. It's a type! This means that we cannot create a variable of type `void` and assigne a value to it. But functions can return `void`s or take them as input arguments. For a function to have a "return value" `void`, simply means that the function doesn't have a return value, and we call them `void functions`. Likewise, if the function "takes an argument" `void`, it simply means that it does not take any arguments.

## Data types in `cs50.h`

The `cs50.h` library includes two other data types that don't exist natively in `C`: boolean values, and strings.

We use `bool` to declare booleans. We use them to store values of `true` or `false`. In `C` all values other than 0 are `truthy`. Zero, in turn, is `false`.

We use `string` to declare string values. These are variables that take more than one character in length.

## Creating and using variables

To create a variable we use:

```c
type name = value;
```

This is called *variable initialization*. We can also breake this up into *declaration* and *assignment* like so

```c
type name; // declaration
name = value; // assignment
```

We can also declare multiple variables in the same line, as long as they all have the same data type.

```c
type name1, name2, name3;
```

It's a `C` best practice not to use this form, but to initialize each variable instead.

The variable type only needs to be included in the declaration. Any and all assignments thereafter don't requier you to specifiy the data type (in fact, doing it can cause problems so it's best to avoid it all together).

# Operators

## Assignment operator

In `C` we use the equal sign, `=`, as the assignment operator.

## Arithmetic operators

`C` allows us to use all four basic arithmetic operators: `+` for addition, `-` for substraction, `*` for multiplication, `/` for division. We also a modulus operator, `%`, which returns the remainder of a division. So, for example, `13 % 4` is 1, because it's the remainder of dividing 13 into 4.

These five operators can be used in assignment as well. So, for example in the code below, `x` is equal to 20, since we initialized it to 10 first, and then added 10 to it.

``` c
int x = 10;
x += 10;
```

This *syntactic sugar* allows us to assign and mutate at the same time with fewer typing. So, `a = a + b` is the same as `a += b`, `a = a * b` is the same as `a *= b`, `a = a - b` is the same as `a -= b`, `a = a / b` is the same as `a /= b`, and `a = a % b` is the same as `a %= b`.

If we are looking to only increment or decrease a value by 1, then we can also use `x++` or `x--`. So `x = x + 1` is the same as `x += 1` or `x++`, and `x = x - 1` is the same as `x -= 1` or `x--`.

## Logical operators

Logical operators include *AND* (represented by `&&`), *OR* (represented by `||`), and *NOT* (represented by `!`). They follow the same rules as in logic. Logical operations evaluate to either `true` or `false`.

## Relational operators

`C` also has relational operators that work the same way they do in math. They are `<` for *less than*, `<=` for *less than or equal to*, `>` for *greater than*, `>=` for *greater than or equal to*, `==` for *equal to*, and `!=` for *not equal to*. Relational operations evaluate to either `true` or `false`.

# Conditional statements

Conditional statements allow your programm to make decisions and take different forks in the road.

## `if` statements

We declare `if` statements as follows:

``` c
if (boolean-expression)
{
  // Do something...
}
```

When the *boolean-expression* evaluates to `true` then the body of the `if` statement will be executed. Otherwise, the program will ignore everything in there.

## `if else` statements

We declare `if else` statements as follows:

``` c
if (boolean-expression)
{
  // Do something...
}
else
{
  // Do something else...
}
```

Like with the `if` statement, when the *boolean-extression* evaluates to `true` then the body of the `if` clause will be evaluated, but not the body of the `else` clause. Likewise, if the *boolean-expression* evaluates to `false`, then the body of the `else` clause will be evaluated, but not the body of the `if` clause. So in summary: *do this, if a condition is met, otherwise, do that*.

## `else if` statements

We can nest `else`s and `if`s with the `else if` statement. It's declared as follows:

``` c
if (bool-exp1)
{
  // branch one
}
else if (bool-exp2)
{
  // branch two
}
else if (bool-exp3)
{
  // branch three
}
else
{
  // branch four
}
```

Here, when *bool-exp1* (short for *boolean-expression-1*) evaluates to `true`, the the first branch of code will be executed. If it evaluates to `false` and *bool-exp2* evaluates to `true` then the second branch of code will be evaluated. We can nest as many `else if` clauses as we need. Keep in mind that they are evaluated in order, so once `C` finds a condition that is staisfied, it will evaluate that branch and not the rest. As always, an `else` clause is optional.

When we need to allow for multiple conditions to be satisfied, we use multiple `if` statements, like so

``` c
if (bool-exp1)
{
  // branch one
}

if (bool-exp2)
{
  // branch two
}

if (bool-exp3)
{
  // branch three
}
else
{
  // branch four
}
```

## `switch` statements

The `switch` statements is used to enumerate a discrete number of distinct cases. We use this statment as follows:

``` c
switch(x)
{
  case 1:
    printf("One!\n");
    break;
  case 2:
    printf("Two!\n");
    break;
  case 3:
    printf("Three!\n");
    break;
  default:
    printf("Game-over!\n");
}
```

Suppose `x` is an `int` that may take values 1, 2, or 3. So when the programm reaches this `swtich` statement, if `x` is 1 it will print out "One!", if `x` is 2 it will print out "Two!", if `x` is 3 it will print out "Three!", and if `x` is anything other 1, 2, or 3 it will print out "Game-over!". The `default` branch is optional but recommended.

We use the `break` clause so that the programm does not *fall through* with the cases. If we don't use it, `C` will start execution at the `case` that meets the criteria, and follow through with executing the others, even the `default`.

## `?:` statements

This statement is sometimes called the *ternary operator*. If is a short hand for an `if else` statement. So the following two snippets are equivalent:

``` c
int x;
if (expr)
{
  x = 5;
}
else
{
  x = 6;
}
```

``` c
int x = (expr) ? 5 : 6;
```

Whatever is after the question mark ,`?`, is what `x` will be if the `expr` is `true`. Whatever is after the colon, `:`, is what `x` will be if `expr` is `false`.

# Loops

Loops are used to execute the same lines of code over and over again. 

## `while` loops

We use a `while` loop to execute a body of code as long as a condition holds `true`. This is very useful when we don't know exactly how many times the code should be executed. We define a `while` loop as follows:

``` c
while (boolean-expression)
{
  // Code to execute
}
```

When using `while` loops it is usually the case that we'll need to keep track of a counter or index variable. We need to remember to augment the counter at each iteration. So, for example, if we want to print every integer between 1 and 100 in the screen, we could use

``` c
int i = 1;
while (i <= 100)
{
  printf("%i\n", i);
  i++;
}
```

If we need to stop (*kill*) a program (maybe because it's stuck in an infinte `while` loop, just press `Ctrl + c`).

## `do while` loops

These are similar to `while` loops, but they first evaluate, and then check the condition. When the condition is `false` they break out of the loop.

``` c
do
{
  // stuff to do
}
while (boolean-expression);
```

Unlike `while` loops, `do while` loops are guranteed to run at least once.

## `for` loops

We use `for` loop to repeat a task a specific number of times. Their syntax is as follows:

``` c
for (int i = 0; i < 10; i++)
{
  // Something to do...
}
```

What this is doing is telling `C` to do is to repeat the operation, starting at 0 and stopping at 10, while incrementing the counter by 1 at each iteration.

More generally, the syntax of a `for` loop is as follows

``` c
for (start; expression; increment)
{
  // Something to do...
}
```

So `C` will first *start* by initializing the counter or counters (yes, we may have more than one). Then it will check if the *expression* is `true`. Then it will *increment* the counter (or counters). Lastly, it will execute the body of the loop. After that, `C` will only execute the expressions in *expression* and *increment* before each iteration. As long as the *expression* evaluates to `true` the counter (or counters) will be incremented, and the body of the loop executed.

# Command Line

## `ls`

The `ls` command (short for *list*) will give you a list of all files and folders on the current directory.

## `cd`

The `cd <directory_name>` command (short for *change directory*) allows us to change the current directory and navigate into the one supplied to the command.

The shorthand name for the current directory is `.` (a dot), and the shorthand name for its parent directory is `..` (two dots). The shorthand name for the root directory is `~` (tilda).

## `pwd`

This command is short for *present working directory* and it will print the name of the working directory you are currently in.

## `mkdir`

This command is short for *make directory* and it allows us to create a new directory which will be a direct child of the current directory we are in. To use it, we run `mkdir <directory_name>`.

## `cp`

We use the `cp` command to *copy* files. It takes two arguments: `cp <source> <destination>`, where `<source>` is the name of the file that we want to copy, and `<destination>` is destintion to which we want to copy the file (aka where to paste it).

To copy an entire directory we use `cp -r <source directory> <destination directory>`. This will copy all the content inside of the `<source directory>` and paste it inside of the `<destination directory>`. The `-r` stands for *recursively*.

## `rm`

We use the `rm <file_name>` command to *remove* files. In some OSs the command line will ask you for a confirmation. You can skip this confirmation by adding the `-f` flag before the name of the file (where `-f` stands for *force*).

Just as when copying, if we want to delete a directory with need to include the `-r` flag. If we don't want to be asked for confirmation at each step of the recursion, we can combine the flags (or pass them separately). So, `rm -rf <directory_name` will delete the directory and eveything inside of it without asking for confirmation.

## `mv`

We use the `mv <source> <destination>` command to move a file from one destination to another. We can use this command to rename files too.
