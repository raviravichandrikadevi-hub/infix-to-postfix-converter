Infix to Postfix Converter in C

Project Description

This project converts infix expressions into postfix expressions using the C programming language. It uses a stack data structure to manage operators and parentheses during conversion.

Project Files

- "main.c" – Reads the input expression and prints the postfix output.
- "infix_postfix.c" – Contains the infix-to-postfix conversion logic.
- "infix_postfix.h" – Contains the public function declarations.
- "stack.c" – Implements the character stack operations.
- "stack.h" – Contains the stack declarations.
- "test_infix_postfix.c" – Contains valid and invalid test cases.
- "Makefile" – Provides commands to compile and test the project.

Supported Syntax

- Single-character alphanumeric operands.
- Operators: "+", "-", "*", "/", "^"
- Parentheses: "(" and ")"
- Whitespace between characters.
- Exponentiation ("^") is right-associative.
- Multiplication and division are left-associative.
- Addition and subtraction are left-associative.

Note: Multi-digit numbers and multi-character identifiers are not tokenized. Each character is treated as a separate operand.

Requirements

- C compiler such as GCC.
- Make utility.
- Linux, macOS, or Windows with GCC/MinGW.

Compilation

Open a terminal in the project directory and run:

make

Execution

Run the compiled program:

./infix_postfix

Enter an infix expression when prompted.

Example

Input:

(A + B) * (C - D) ^ E

Expected Output:

AB+CD-E^*

Running Tests

Execute the test suite using:

make test

The test program exits with status "0" only if every included test passes.

Conclusion

This project demonstrates infix-to-postfix expression conversion in C using a stack data structure. It is organized into multiple source and header files to make the code modular, reusable, and easier to maintain.
