# Stacks, Queues - LIFO, FIFO
##### Monty ByteCode Interpreter
---
#### Description
### Monty is a scripting language similar to Python in which it is first compiled into Monty byte codes. It requires a stack and a set of text file instructions to manipulate. The goal of this project is to create an interpreter for Monty ByteCode Files.
---
### Usage
## $ ./monty 'file'
- Includes `monty.h`
- The file argument must have a .m extension. 
- Included in the file should be the instructions for the byte code interpreter:
```
user:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
push 3$
pall    $
push 4$
push 5    $
      push    6        $
pall$
```
- These instructions can contain blank lines and any number of spaces before or after the opcode argument.

### OpCodes
OpCode | Description
--- | --- 
`push <int>` | pushes an element to the stack
`pall` | prints all the values on the stack, starting from the top of the stack
'pint' | prints the value at the top of the stack, followed by a new line
'pop' | removes the top element of the stacks
'swap' | swaps the top two elements of the stacks
'add' | adds the top two elements of the stack
'nop' | doesn’t do anything
'sub' | subtracts the top element of the stack from the second top element of the stack
'div' | divides the second top element of the stack by the top element of the stack
'mul' | multiplies the second top element of the stack with the top element of the stacks
'mod' | computes the rest of the division of the second top element of the stack by the top element of the stack

### Files

File Name | Description
--- | ---
`main.c` | The entry point for the Monty Byte Code Interpreter. Reads the text file and passes tokens to the compare function
`compare.c` | Contains the struct with the function pointers to each OpCode and compares the line from the textfile to its appropriate function
`monty.h` | Header file with function prototypes and structs
`stackfuncs1.c` | Contains the functions for opcode "push, pint and pall"
`stackfuncs2.c` | Contains the functions for opcode "pop, swap, add, nop"
`stackfuncs3.c` | Contains the functions for opcode "sub, mul, divide, mod"
`error.c` | Error handling file
`freeFunctions.c` | Contains functions that free global and local variables and the stack

---

### About
This project was created by
* **Jeremy Antonio** - [GitHub - jembantonio](https://github.com/jembantonio) | [LinkedIn](https://www.linkedin.com/in/jeremyantonio/) at [Holberton
School](http://holbertonschool.com).
* **Josef Goodyear** - [GitHub - JosefGoodyear](https://github.com/JosefGoodyear) | [LinkedIn](https://www.linkedin.com/in/josefgoodyear/) at [Holberton
School](http://holbertonschool.com).

All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4` with
the following flags:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`.

