#include "stack.h"
#include <stdlib.h>

int stack_init(Stack *s, size_t capacity)
{
    if (s == NULL || capacity == 0) return 0;
    s->items = (char *)malloc(capacity * sizeof(char));
    if (s->items == NULL) {
        s->top = 0;
        s->capacity = 0;
        return 0;
    }
    s->top = 0;
    s->capacity = capacity;
    return 1;
}

int stack_push(Stack *s, char value)
{
    if (s == NULL || s->items == NULL || s->top >= s->capacity) return 0;
    s->items[s->top++] = value;
    return 1;
}

int stack_pop(Stack *s, char *value)
{
    if (s == NULL || value == NULL || s->items == NULL || s->top == 0) return 0;
    *value = s->items[--s->top];
    return 1;
}

int stack_peek(const Stack *s, char *value)
{
    if (s == NULL || value == NULL || s->items == NULL || s->top == 0) return 0;
    *value = s->items[s->top - 1];
    return 1;
}

int stack_is_empty(const Stack *s)
{
    return s == NULL || s->top == 0;
}

void stack_destroy(Stack *s)
{
    if (s == NULL) return;
    free(s->items);
    s->items = NULL;
    s->top = 0;
    s->capacity = 0;
}
