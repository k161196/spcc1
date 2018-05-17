%{ 
#include<stdio.h> 
%} 
%% 
#define printf("\n CONSTANT = %s",yytext); 
#include|int|float|switch|for|while|else|if|void|case|break|printf|goto|struct|const|do|return|sizeof printf("\nKeyword - %s",yytext); 
[a-zA-Z|_]+[(a-zA-Z)|[0-9]|_]* printf("\nIdentifier - %s",yytext); 
[-,+]?[0-9]+ printf("\nConstants - %s",yytext); 
[!@#$^'"]+ printf("\nSpecial Chars - %s",yytext); 
[{|(]+ printf("\nLeft Parenthesis - %s",yytext); 
[}|)]+ printf("\nRight Parenthesis - %s",yytext); 
[\n\t]+ printf("\nESCAPE - %s",yytext); 
[ ] printf(" "); 
[+,-,*,/,=]+ printf("\nOperater - %s",yytext); 
[<,>,=,!]=? printf("\nRel operator - %s",yytext); 
[&&,||,!]+ printf("\nLogical operator - %s",yytext); 
[;]+ printf("\nDelimiter - %s",yytext); 
%% 
main(){yylex();} 
