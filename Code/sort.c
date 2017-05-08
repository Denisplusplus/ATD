#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.h"
#include "sort.h"

#define stack_size 1


void help()
{
    printf("The main function of this app is working with ATD: STACK. \n");
    printf("Use this keys to work with the program: \n");
    printf("- 'add' - to insert the value in the stack\n");
    printf("- 'print' - to print the stack \n");
    printf("- 'destroy' - to delete the stack \n");
    printf("- 'sort' - to start sorting the stack with Hoare's quick sort algorithm\n");
    printf("- 'exit' or 'quit' - to quit the application\n");
}

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


Stack* stack_concatenation(Stack* right, Stack* left, Item* pivot)
{
    Stack* temp = stack_create(stack_size);
    while(!stack_is_empty(right)) {
        stack_push(temp, stack_pop(right));
    }
    stack_push(temp, pivot);
    while(!stack_is_empty(left)) {
        stack_push(temp, stack_pop(left));
    }
    stack_destroy(&right);
    stack_destroy(&left);
    return temp;
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

    Stack* temp = stack_concatenation(right, left, pivot);
    while(!stack_is_empty(temp)) {
        stack_push(stack, stack_pop(temp));
    }
    stack_destroy(&temp);
    return stack;
}
