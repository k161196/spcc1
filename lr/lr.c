#include<stdio.h>
#include<string.h>
int main()
{  char non_terminal;
    char terminal;
    char beta,alpha[10];
    int i,num;
    int index=3;
    char production[10][10];
   printf("enter the number of production rules");
    scanf("%d\n",&num);
    for(i=0;i<num;i++){
    scanf("%s",production[i]); }
    printf("%d\n",num);
    for(i=0;i<num;i++){
        printf("%s",production[i]);
        non_terminal=production[i][0];
        if(non_terminal==production[i][index]){
          alpha[0]=production[i][index+1];
          if(production[i][index+2]!='|')
          {
          alpha[1]=production[i][index+2];
          } 
                 printf(" is left recursive.\n");
                 while(production[i][index]!=0 && production[i][index]!='|') 
                  { 
                      index++;  } 
                if(production[i][index]!=0)  {
                      beta=production[i][index+1];
                      printf("Grammar without left recursion:\n");
                      printf("%c->%c%c\'",non_terminal,beta,non_terminal);
                      printf("\n%c\'->%c%c%c\'|^\n",non_terminal,alpha[0],alpha[1],non_terminal);
                       }
                 else
                      printf(" can't be reduced\n");
            }
            else
                 printf(" is not left recursive.\n");
            index=3;
       }
printf("hello\n");
    return 0;
}
/*
code@code-Aspire-A515-51G:~/Pictures/code$ gcc lr.c
code@code-Aspire-A515-51G:~/Pictures/code$ ./a.out
enter the number of production rules1
A->A+T|a
1
A->A+T|a is left recursive.
Grammar without left recursion:
A->aA'
A'->+TA'|^
hello
*/