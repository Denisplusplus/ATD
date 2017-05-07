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


Stack* stack_concatenation(Stack* stack_first, Stack* stack_second)
{


    Stack *temp = stack_create(stack_size);
    while (!stack_is_empty(stack_second)) {
        stack_push(temp, stack_pop(stack_second));
    }

    while (!stack_is_empty(temp)) {
        stack_push(stack_first, stack_pop(temp));
    }


    return stack_first;

}

Stack* stack_quick_sort(Stack* stack)
{
    if (stack_is_empty(stack)) {
        return stack;
    }

    Item pivot = stack_pop(stack);

    Stack* left  = stack_create(stack_size);
    Stack* right = stack_create(stack_size);
    while(!stack_is_empty(stack)) {
        Item value = stack_pop(stack);
        if (value > pivot) {      
            stack_push(left, value);
        } else {
            stack_push(right, value);
        }
    }

    stack_quick_sort(left);
    stack_quick_sort(right);
         
    Stack* temp = stack_create(stack_size);
    while(!stack_is_empty(right)) {
        stack_push(temp, stack_pop(right));
    }
    stack_push(temp, pivot);
    while(!stack_is_empty(left)) {
        stack_push(temp, stack_pop(left));
    }
    while(!stack_is_empty(temp)) {
        stack_push(stack, stack_pop(temp));
    }

    return stack;
}


int main(void)
{

    Stack *stack_1 = stack_create(stack_size);
    Stack *stack_2 = stack_create(stack_size);
    Item element = 0;

   int n = 0;
   int m = 0;

   scanf("%d\n", &n);
   scanf("%d\n", &m);

   for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        stack_push(stack_1, element);
   }
   for (int i = 0; i < m; i++) {
        scanf("%d", &element);
        stack_push(stack_2, element);
   }

    stack_quick_sort(stack_1);
    stack_quick_sort(stack_2); 
    stack_print(stack_concatenation(stack_1, stack_2));
    return 0;
}

