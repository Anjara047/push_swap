*This project has been created as part of the 42 curriculum by tsiarran, tsanjara.*

# Push_swap

## Description

### Generality

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Push_swap is a project from the 42 curriculum focused on designing an efficient sorting algorithm. Its objective is to sort a stack of integers using a limited set of operations while minimizing the total number of moves.

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The program takes an unsorted sequence as input and, through an optimized algorithm, outputs a series of instructions that results in a fully sorted stack.

### Goal

 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The primary objective is to minimize the number of operations required to achieve a fully sorted stack. This involves analyzing algorithmic complexity based on input size and selecting the most efficient strategy to ensure optimal performance.

### Rules

You are allowed to use only two stacks, generally named A and B.

At the beginning:<br>
* Stack A : contains a random list of integers (input)  
* Stack B : is initially empty  

At the end:<br>
* Stack A : contains the sorted list of integers after execution  
* Stack B : is empty  

### Allowed Operations

• `sa`  : swap the first two elements of stack A  
• `sb`  : swap the first two elements of stack B  
• `ss`  : sa and sb at the same time  
• `pa`  : push the top element from B to A  
• `pb`  : push the top element from A to B  
• `ra`  : rotate A (first element becomes last)  
• `rb ` : rotate B  
• `rr ` : ra and rb  
• `rra` : reverse rotate A (last becomes first)  
• `rrb` : reverse rotate B  
• `rrr` : `rra` and `rrb` 


## Instructions

### Compilation

```bash
make			# Compile the program
make clean		# Remove object files (.o)
make fclean		# Remove object files and the library file
make re			# Recompile the program
```
### Execution


```bash
					./push_swap 4 67 3 87 23
ARG="4 67 3 87 23"; ./push_swap  $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --simple $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --medium $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --bench $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap --complex --bench $ARG | ./checker_linux $ARG
```

## Resources

* Thanks to the 42 School learning system, particularly the peer-to-peer methodology, which greatly helped in understanding the project's objectives and expectations.
* Online documentation and tutorials, which provided ideas and inspiration for Algorithms, strategies, and implementation technics

### Use of AI

* AI tools were used as learning aids to better understand expected behaviors, clarify edge cases, and verify reasoning while debugging.
* AI was not used to directly generate the project solution, but to assist with explanations, documentation writing, and overall project organization.

## Algorithms

### Parsing
In order to sort the input, the parsing function converts the provided arguments into int and stores them in the stack A

### Strategy
#### Simple Strategy

Based on an insertion-like approach.

* Find the minimum value in stack A
* Move it to the top:

  * use `ra` if it is closer to the top
  * use `rra` if it is closer to the bottom
* Push it to stack B (`pb`)
* Repeat the process
* Push everything back to A (`pa`)

---

#### Medium Strategy

Based on a chunk system.

* Divide stack A into chunks
* Process chunk by chunk
* Push elements belonging to the current chunk from A to B
* Continue until all chunks are pushed
* Rebuild A from B

---

#### Complex Strategy

Based on radix sort.

* Process numbers bit by bit
* If bit = 0 → push to B (`pb`)
* If bit = 1 → rotate A (`ra`)
* After each pass, push everything back to A (`pa`)

