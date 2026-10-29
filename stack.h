#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct {
    char *items;
    size_t top;
    size_t capacity;
} Stack;

int stack_init(Stack *s, size_t capacity);
int stack_push(Stack *s, char value);
int stack_pop(Stack *s, char *value);
int stack_peek(const Stack *s, char *value);
int stack_is_empty(const Stack *s);
void stack_destroy(Stack *s);

#endif
