%{
#include <stdio.h>
#include "calc.tab.h"  // Include the YACC-generated header
#include <stdlib.h> // For atoi
%}

space " "
%%

[0-9]+ {
    yylval = atoi(yytext); // Convert number to integer
    return NUMBER;         // Return token to YACC
}

{space} ;                  // Ignore spaces
[\t] ;                     // Ignore tabs
[\n] return 0;             // Handle newlines (end of input)
. return yytext[0];        // Return other single characters as-is

%%

int yywrap() {
    return 1;              // Indicate EOF
}
