%{
#include<stdio.h>
%}
%%
char|int|float|main|static|void|for|if|do|while|return printf("Keyword :%s\n",yytext );
[-,+]?[0-9]+ printf("Constants :%s\n",yytext);
[,.'"]+ printf("Punctuation Chars :%s \n",yytext);
[!@#$%^&*()]+ printf("Special Chars :%s\n",yytext);
[a-zA-Z]+ printf("Identifiers :%s\n",yytext);
[+,-,*,/,]+ printf("Operators :%s\n",yytext);
%%
int main(){yylex();}