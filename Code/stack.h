#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

#define MEMORY_LIMIT 1
#define STACK_UNDERFLOW 2
#define STACK_OVERFLOW 3

typedef int Item;
typedef struct _stack Stack;

Stack *stack_create(size_t stack_size);

Item stack_pop(Stack *s);
Item stack_top(Stack *s);

bool stack_is_empty(Stack *s);

void stack_push(Stack *s, Item value);
void stack_destroy(Stack **s);


#endif
