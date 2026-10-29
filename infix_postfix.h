#ifndef INFIX_POSTFIX_H
#define INFIX_POSTFIX_H

#include <stddef.h>

/*
 * Converts an infix expression to postfix.
 * Operands: single letters/digits (A, x, 7, etc.).
 * Operators: + - * / ^ and parentheses.
 * Whitespace is ignored.
 * Returns 1 on success, 0 on invalid input or insufficient output buffer.
 */
int infix_to_postfix(const char *infix, char *postfix, size_t postfix_size);

#endif
