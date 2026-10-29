#include "infix_postfix.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    const char *input;
    const char *expected;
} TestCase;

int main(void)
{
    const TestCase tests[] = {
        {"A+B", "AB+"},
        {"(A+B)*(C-D)^E", "AB+CD-E^*"},
        {"A+B*C", "ABC*+"},
        {"(A+B)*C", "AB+C*"},
        {"A-B-C", "AB-C-"},
        {"A^B^C", "ABC^^"},
        {"(A^B)^C", "AB^C^"},
        {"A*(B+C/D)", "ABCD/+*"},
        {"a + b * (c - d)", "abcd-*+"},
        {"1+3", "13+"},
        {"A/B*C", "AB/C*"},
        {"((A))", "A"}
    };
    const char *invalid[] = {
        "", " ", "+A", "A+", "A**B", "(A+B", "A+B)", "()",
        "A(B)", "AB", "A+*B", "A@B", "A+(B*)"
    };
    char output[256];
    size_t i;
    int failed = 0;
    int total = (int)(sizeof tests / sizeof tests[0]) +
                (int)(sizeof invalid / sizeof invalid[0]);

    for (i = 0; i < sizeof tests / sizeof tests[0]; ++i) {
        int ok = infix_to_postfix(tests[i].input, output, sizeof output);
        if (!ok || strcmp(output, tests[i].expected) != 0) {
            printf("FAIL valid: [%s] expected [%s], got [%s]\n",
                   tests[i].input, tests[i].expected, ok ? output : "ERROR");
            failed++;
        } else {
            printf("PASS valid: %s -> %s\n", tests[i].input, output);
        }
    }

    for (i = 0; i < sizeof invalid / sizeof invalid[0]; ++i) {
        int ok = infix_to_postfix(invalid[i], output, sizeof output);
        if (ok) {
            printf("FAIL invalid: [%s] unexpectedly converted to [%s]\n",
                   invalid[i], output);
            failed++;
        } else {
            printf("PASS invalid: [%s] rejected\n", invalid[i]);
        }
    }

    printf("\nResult: %d/%d tests passed.\n", total - failed, total);
    return failed == 0 ? 0 : 1;
}
