%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}[\n]* {
    printf("Valid email: %s\n", yytext);
}

\n {
    // Ignore newlines
}

. {
    printf("Invalid email: %s\n", yytext);
}

%%

int main() {
    printf("Enter an email to validate:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
