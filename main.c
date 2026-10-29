#include "infix_postfix.h"

#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 1024
#define OUTPUT_SIZE 2048

int main(void)
{
    char infix[INPUT_SIZE];
    char postfix[OUTPUT_SIZE];

    printf("Enter infix expression: ");
    if (fgets(infix, sizeof infix, stdin) == NULL) {
        fprintf(stderr, "Error: no input received.\n");
        return 1;
    }
    infix[strcspn(infix, "\n")] = '\0';

    if (!infix_to_postfix(infix, postfix, sizeof postfix)) {
        fprintf(stderr, "Error: invalid expression or output buffer too small.\n");
        return 1;
    }

    printf("Postfix: %s\n", postfix);
    return 0;
}
