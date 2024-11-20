%{
#include <stdio.h>
int word = 0;
int id = 0;
int key = 0;
%}

%%

[0-9]+ {
    printf("<Numerical,%s>\n", yytext);
    word++;
}

(int|for|while|double|char|main|if|do) {
    printf("<Keyword,%s>\n", yytext);
    word++;
    key++;
}

[\+\=\-\*\%\/] {
    printf("<Operator,%s>\n", yytext);
}

[a-zA-Z][a-zA-Z0-9_]* {
    printf("<Identifier,%s>\n", yytext);
    word++;
    id++;
}

[\,\.\:\"\'\;\(\)\{\}] {
    printf("<Punctuation,%s>\n", yytext);
}

[ \t\n]+ {
    // Ignore whitespace
}

. {
    printf("<Unrecognized,%s>\n", yytext);
}

%%

int main() {
    yylex();
    printf("<No of words: %d>\n", word);
    printf("<No of identifiers: %d>\n", id);
    printf("<No of keywords: %d>\n", key);
    return 0;
}

int yywrap() {
    return 1;
}
