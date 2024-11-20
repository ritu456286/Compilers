
%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

"int"|"float"|"char"|"if"|"else"|"while"|"return"|"main"|"printf" {
    printf("KEYWORD: %s\n", yytext);
} // Matches C keywords

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("IDENTIFIER: %s\n", yytext);
} // Matches identifiers

[0-9]+ {
    printf("NUMBER: %s\n", yytext);
} // Matches numbers

"==" {
    printf("EQUALS: %s\n", yytext);
} // Matches '=='

"+" {
    printf("PLUS: %s\n", yytext);
} // Matches '+'

"-" {
    printf("MINUS: %s\n", yytext);
} // Matches '-'

"*" {
    printf("ASTERISK: %s\n", yytext);
} // Matches '*'

"/" {
    printf("SLASH: %s\n", yytext);
} // Matches '/'

"=" {
    printf("EQUAL: %s\n", yytext);
} // Matches '='

"(" {
    printf("LPAREN: %s\n", yytext);
} // Matches '('

")" {
    printf("RPAREN: %s\n", yytext);
} // Matches ')'

"{" {
    printf("LBRACE: %s\n", yytext);
} // Matches '{'

"}" {
    printf("RBRACE: %s\n", yytext);
} // Matches '}'

";" {
    printf("SEMICOLON: %s\n", yytext);
} // Matches ';'

[ \t\r]+ {
    /* Skip spaces and tabs */
}

\n {
    /* Skip newlines */
}

. {
    printf("UNKNOWN TOKEN: %s\n", yytext);
} // Matches any unknown token

%%

int main() {
    printf("Enter your code (press Ctrl+C to end):\n");
    yylex(); // Call the lexical analyzer
    return 0;
}

int yywrap() {
    return 1;
}
