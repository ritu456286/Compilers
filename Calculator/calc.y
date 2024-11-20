+



































+%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;                 // Flag for error tracking
extern int yylex(void);       // LEX function
extern void yyerror(const char *s); // Error function
%}

%token NUMBER                // Declare token for numbers
%left '+' '-'                // Define precedence for addition/subtraction
%left '*' '/'                // Define precedence for multiplication/division
%left '(' ')'                // Parentheses have the highest precedence

%%

ArithmeticExpression:
    E {
        printf("Result = %d\n", $1);  // Print the final result
        return 0;
    }
;

E:
    E '*' E { $$ = $1 * $3; }          // Multiplication
  | E '/' E { 
        if ($3 == 0) {                // Handle division by zero
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
  | E '+' E { $$ = $1 + $3; }         // Addition
  | E '-' E { $$ = $1 - $3; }         // Subtraction
  | '(' E ')' { $$ = $2; }            // Parentheses
  | NUMBER { $$ = $1; }               // Numbers
;

%%

void main() {
    printf("\nEnter Any Arithmetic Expression:\n");
    yyparse(); // Start parsing

    if (flag == 0) {
        printf("\nEntered arithmetic expression is Valid\n\n");
    }
}

void yyerror(const char *s) {
    printf("\nError: %s\n", s);        // Print error message
    flag = 1;                         // Set error flag
}
