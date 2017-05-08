#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.h"
#include "sort.h"

#define stack_size 1


int main(void)
{
    char s[8];
    Stack* stack = stack_create(stack_size);
    Item value = 0;

    printf("\nType 'help' to gain information how to use the app.\n\n");

    while (true) {
        scanf("%7s", s);
        if (!strcmp(s, "add")) {
            while (scanf("%d", &value))
              stack_push(stack, value);
        } else
        if (!strcmp(s, "print")) {
            printf("\n\n");
            if (stack_is_empty(stack)) {
                printf("Stack is empty.\n");
            }
            stack_print(stack);
            printf("\n\n");
        } else
        if (!strcmp(s, "destroy")) {
            stack_destroy(&stack);
        } else
        if (!strcmp(s, "help")) {
            help();
        } else
        if (!strcmp(s, "sort")) {
            if (stack_is_empty(stack)) {
                printf("Stack is empty. Nothing to sort.\n");
            } else
            stack_quick_sort(stack);
        } else
        if (!strcmp(s, "quit") || !strcmp(s, "exit")) {
            stack_destroy(&stack);
            break;
        } else {
            printf("An error occurred. Type 'help' to find the solution\n");
            stack_destroy(&stack);
            exit(1);
        }   
    }


    return 0;
}

