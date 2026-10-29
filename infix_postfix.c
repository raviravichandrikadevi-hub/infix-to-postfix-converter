#include "infix_postfix.h"
#include "stack.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

static int precedence(char c)
{
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

static int is_right_associative(char c)
{
    return c == '^';
}

int infix_to_postfix(const char *infix, char *postfix, size_t postfix_size)
{
    size_t i, out = 0, n;
    int expect_operand = 1;
    Stack stack;
    char top, c;

    if (infix == NULL || postfix == NULL || postfix_size == 0) return 0;
    postfix[0] = '\0';
    n = strlen(infix);
    if (n == 0 || !stack_init(&stack, n + 1)) return 0;

    for (i = 0; i < n; ++i) {
        c = infix[i];
        if (isspace((unsigned char)c)) continue;

        if (isalnum((unsigned char)c)) {
            if (!expect_operand) goto invalid;
            if (out + 1 >= postfix_size) goto invalid;
            postfix[out++] = c;
            expect_operand = 0;
        } else if (c == '(') {
            if (!expect_operand || !stack_push(&stack, c)) goto invalid;
            expect_operand = 1;
        } else if (c == ')') {
            if (expect_operand) goto invalid;
            while (stack_peek(&stack, &top) && top != '(') {
                if (!stack_pop(&stack, &top) || out + 1 >= postfix_size) goto invalid;
                postfix[out++] = top;
            }
            if (!stack_pop(&stack, &top) || top != '(') goto invalid;
            expect_operand = 0;
        } else if (is_operator(c)) {
            if (expect_operand) goto invalid;
            while (stack_peek(&stack, &top) && is_operator(top) &&
                   (precedence(top) > precedence(c) ||
                    (precedence(top) == precedence(c) && !is_right_associative(c)))) {
                if (!stack_pop(&stack, &top) || out + 1 >= postfix_size) goto invalid;
                postfix[out++] = top;
            }
            if (!stack_push(&stack, c)) goto invalid;
            expect_operand = 1;
        } else {
            goto invalid;
        }
    }

    if (expect_operand) goto invalid;
    while (stack_pop(&stack, &top)) {
        if (top == '(' || out + 1 >= postfix_size) goto invalid;
        postfix[out++] = top;
    }
    postfix[out] = '\0';
    stack_destroy(&stack);
    return 1;

invalid:
    postfix[0] = '\0';
    stack_destroy(&stack);
    return 0;
}
