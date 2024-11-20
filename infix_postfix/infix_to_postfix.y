%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

/* Token Definitions */
%token NUMBER
%token PLUS MINUS MULTIPLY DIVIDE
%token LPAREN RPAREN

/* Operator Precedence and Associativity */
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right UMINUS

/* Grammar Rules and Actions */
%%
expression:
    expression PLUS expression       { printf("+ "); }
    | expression MINUS expression    { printf("- "); }
    | expression MULTIPLY expression { printf("* "); }
    | expression DIVIDE expression   { printf("/ "); }
    | LPAREN expression RPAREN       { /* Parentheses for grouping */ }
    | MINUS expression %prec UMINUS  { printf("~ "); }
    | NUMBER                         { printf("%d ", $1); }
    ;
%%
int main() {
    printf("Enter an infix expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
