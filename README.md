# C - Stacks, Queues - LIFO, FIFO Interpretation by Monty Language

## The Monty Language
 
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. In this project, I learnt how to create an interpreter for Monty ByteCode files.

### Getting Started
- Ubuntu 20.04 LTS - Operating system required.

- GCC 9.4.0 - Compiler used

### What’s Required
- Ubuntu Terminal or any other VM Sandbox

### Installation and Usage
Clone the repository into a new directory:

`$ git clone https://github.com/felixayot/monty.git`

Compile with the following:

`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

Run the interpreter on a file:

`./monty file.m`

### Monty Opcodes
- **push**

`Usage: push <int>`


Pushes an element to the stack.

The parameter <int> must be an integer.

- **pall**
	
	Prints all values in the stack/queue, starting from the top.

- **pint**
	
	Prints the top value of the stack/queue.

- **pop**
	
	Removes the top element of the stack/queue.

- **swap**
	
	Swaps the top two elements of the stack/queue.

- **nop**
	
	Does not do anything.

- **add**
	
	Adds the top two elements of the stack/queue.
	
	The result is stored in the second element from the top and the top element is popped.

- **sub**
	
	Subtracts the top element of the stack/queue from the second element from the top.
	
	The result is stored in the second element from the top and the top element is removed.

- **mul**
	
	Multiplies the top two elements of the stack/queue.
	
	The result is stored in the second element from the top and the top element is removed.

- **div**
	
	Divides the second element from the top of the stack/queue by the top element.
	
	The result is stored in the second element from the top and the top element is removed.

- **mod**
	
	Computes the modulus of the second element from the top of the stack/queue divided by the top element.
	
	The result is stored in the second element from the top and the top element is removed.

- **pchar**
	
	Prints the character value of the top element of the stack/queue.
	
	The integer at the top is treated as an ASCII value.

- **pstr**
	
	Prints the string contained in the stack/queue.
	
	Prints characters element by element until the stack/queue is empty, a value is 0, or an error occurs.

- **rotl**
	
	Rotates the top element of the stack/queue to the bottom.

- **rotr**
	
	Rotates the bottom element of the stack/queue to the top.

- **stack**
	
	Switches a queue to stack mode.

- **queue**
	
	Switches a stack to queue mode.
  
	Opcodes preceded by a `#` are treated as comments and the corresponding line is ignored.
  
	Lines can be empty and can contain any number of spaces before or after an opcode and its argument (only the first opcode and/or argument is taken into account).

## Examples
You can try out your own additional examples by creating a Monty file with the file extension .m and running the Monty interpreter as per the usage stated above. See below for guidance.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
	$ cat monty_bytecode.m
	push 1
	pint
	push 2
	pint
	push 3
	pint
	$ ./monty monty_bytecode.m
	1
	2
	3
```
# Authors
- ***Felix Ayot*** - felixayot@gmail.com

# Acknowledgments
- ALX SE program provided the resources and project guidance.
