# Compilers Projects

This repository contains various projects and tools related to compilers, built as part of academic exercises or personal learning. Each folder represents a specific component or utility used in compiler design.
## Prerequisites

1. C/C++ Compiler - like MinGW
2. Flex - Fast Lexical Analayser for lexical analysis
3. Bison - Modern version of YACC (Yet another Compiler Compiler) for parsing.

## Directory Structure

### 1. `assembler`
A project for implementing a two pass assembler.

### 2. `C_Lex_Analyzer`
A lexical analyzer for the C programming language, designed to tokenize C code into lexemes.

### 3. `Calculator`
A simple calculator program capable of parsing and evaluating mathematical expressions.

### 4. `CFG_for_C`
Context-Free Grammar (CFG) for the C programming language, used for syntactic analysis.

### 5. `email_val`
An email validation tool, which checks the validity of email addresses using regular expressions and syntax rules.

### 6. `infix_postfix`
A program to convert expressions from infix notation (e.g., `a + b`) to postfix notation (e.g., `ab+`), often used in compilers for expression evaluation.

### 7. `Symbol_Table`
Implementation of a symbol table, a key data structure in compilers for tracking variable declarations, scopes, and types.

### 8. `Tokenization`
A standalone project for tokenizing input strings, breaking them into meaningful units (tokens) for further processing.

---

## How to Run

Each project is designed as a standalone module. Follow the steps below to set up and run:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/compilers-projects.git
   cd compilers-projects
   ```
2. **Navigate to the Desired Project:**
  ```bash
   cd compilers-projects
   ```
3. **Compile and Run:**
  ```bash
   gcc main.c -o main
  ./main
   ```
