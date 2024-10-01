Overview

The project demonstrates the fundamental concepts of compilers, such as lexical analysis, parsing, abstract syntax tree (AST) generation, and assembly code generation. It is ideal for students or developers looking to explore compiler construction and CPU simulation.

Features

Simple Syntax: Supports variable declarations, assignments, arithmetic operations, and basic conditional statements (e.g., if statements).
Compiler Stages:
Lexer: Tokenizes the source code into meaningful symbols.
Parser: Converts tokens into an Abstract Syntax Tree (AST).
Code Generator: Translates the AST into assembly code for the 8-bit CPU.
8-bit CPU Compatibility: Designed to generate assembly code that runs on a custom 8-bit CPU simulator.
Language Constructs
Variable Declaration: int a;
Assignment: a = b + c;
Arithmetic Operations: +, -
Conditionals: if (a == b) { a = a + 1; }
Project Structure
lexer.h / lexer.c: Handles lexical analysis and tokenization.
parser.h / parser.c: Parses tokens into an AST and manages program structure.
codegen.h / codegen.c: Generates assembly code from the AST.
main.c: Entry point of the program; coordinates the compilation stages.

Dependencies

A C compiler (e.g., gcc)
8-bit CPU Simulator (optional)

Contributions are welcome! Feel free to open issues or submit pull requests with improvements, bug fixes, or additional features.
