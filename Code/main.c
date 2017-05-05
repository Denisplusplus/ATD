#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.h"

#define stack_size 1

void stack_print(Stack *stack)
{
    Stack *helper_stack = stack_create(stack_size);
    while(!stack_is_empty(stack)) {
        printf("%d\n", stack_top(stack));
        stack_push(helper_stack, stack_pop(stack));
    }
    while(!stack_is_empty(helper_stack)) {
        stack_push(stack, stack_pop(helper_stack));
    }
    stack_destroy(&helper_stack);
}

void insert_to_bottom(Stack* stack, int value)
{
	if (stack_is_empty(stack)) {
		stack_push(stack, value);
	} else {
		Item temp = stack_pop(stack);
		insert_to_bottom(stack, value);
		stack_push(stack, temp);
	}

}

Stack* stack_reverse(Stack* stack)
{
	Stack* new_stack= stack_create(stack_size);
	while(!stack_is_empty(stack)) {
		stack_push(new_stack, stack_pop(stack));
	}
	return(new_stack);
}


Stack* quick_sort(Stack* stack)
{
  if (stack_is_empty(stack)) {
    return stack;
  }

  Item pivot = stack_pop(stack);
   
  // partition
  Stack* left  = stack_create(stack_size);
  Stack* right = stack_create(stack_size);
  while(!stack_is_empty(stack)) {
    Item value = stack_pop(stack);
    if (value < pivot) {      
      stack_push(left, value);
    } else {
      stack_push(right, value);
    }
  }
  quick_sort(left);
  quick_sort(right);
    
 
  Stack* temp = stack_create(stack_size);
  Stack* new_stack = stack_create(stack_size);
  while(!stack_is_empty(right)) {
    stack_push(temp, stack_pop(right));
  }
  stack_push(temp, pivot);
  while(!stack_is_empty(left)) {
     stack_push(temp, stack_pop(left));

  }
  while(!stack_is_empty(temp)) {
      stack_push(new_stack, stack_pop(temp));

  }
  while(!stack_is_empty(new_stack)) {
      stack_push(stack, stack_pop(new_stack));

  }

  return stack;
}


int main(void)
{

   Stack *stack = stack_create(stack_size);

   Item element = 0;

   int n=0;
   scanf("%d\n", &n);
   for (int i=0; i<n;i++) {
        scanf("%d", &element);
        stack_push(stack, element);
   }


   stack_print(stack);
   quick_sort(stack);
   stack_print(stack);
  
    return 0;
}

