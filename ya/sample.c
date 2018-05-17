#include <stdio.h> 
void main () { 
   int a0z = 5; 
   if ( a&&b ) 
      printf ("Line 1 - Condition is true \n"); 
    else 
      printf ("Line 1 - Condition is not true \n"); 
   if ( a < b ) 
   break;	 
} 
students@celab6-19:~$ flex lexi.l 
students@celab6-19:~$ gcc lex.yy.c -ll 
students@celab6-19:~$ ./a.out < sample.c >> text69.txt 
