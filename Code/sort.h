#ifndef _SORT_H_
#define _SORT_H_

void help(void);
void stack_print(Stack *stack);
Stack* stack_concatenation(Stack* right, Stack* left, Item* pivot);
Stack* stack_quick_sort(Stack* stack);

#endif
