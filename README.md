# ATD | Recursion | Makefile
### The task №3:
Procedure: STACK concatenation </br>
Method: Hoare's quicksort
### Algorithm:
Realize these actions:
  * Create the stack
  * Add the element to the stack (push)
  * Pull out the element from the stack (pop)
  * Return the topmost element of the stack (top)
  * Destroy the stack (destroy)
  * Check the emptiness of the stack 
  * Quick sort 
### Algorithm of Hoare's quick sort
Algoritm includes following:
* Choose a pivot (supporting element)
* Devide stack into two stacks(right and left)
* The elements that are less then pivot we put into right stack, others- to the left stack
* Then we do the previous steps for right and left sctacks
* Concatenate right and left stack and the pivot in the one stack
* Return this stack
##### Realize these functions to launch the qsort:
* stack_print(Stack* stack)
* stack_sort(Stack* stack)
* stack_concatenate(Stack* right, Stack* left, Item* pivot)
### Testing:
----- </br>
I | O </br>
-----</br>
1 | 1 </br>
2 | 2 </br>
3 | 3 </br>
----- </br>
2 | 1 </br>
1 | 2 </br>
3 | 3 </br>
----- </br>
1 | 1 </br>
----- </br>
3 | 1 </br>
2 | 2 </br>
1 | 3 </br>
----- </br>
### How to use:
* Download this folder to your PC
* Type 'make' to compile
* Launch by typing ./start
* Type 'help' to gain the information about the keys to control the app 

Here is the keys description:
* 'add' - to insert the value in the stack
* 'print' - to print the stack 
* 'destroy' - to delete the stack 
* 'sort' - to start sorting the stack with Hoare's quick sort algorithm
* 'exit' or 'quit' - to quit the application




