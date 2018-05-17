import java.io.*;
import java.util.*;
class Quad{
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the valid string ");
        String s=sc.next();
        char a[][]= new char[10][10];
        System.out.println("string"+s.indexOf("i"));
       Stack<String> stack  =new Stack<String>();
       int count = 1;
       System.out.println("| Operator | op1 | op2 | result |");
        for(int i=0;i<s.length();i++)
        {
            char c = s.charAt(i);
            if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
            {
                String op2 = stack.pop();
                String op1 = stack.pop();
           
                System.out.println("|     "+c+"    |  "+op1+"  |  "+op2+"  |   "+"t"+count+"   |");
                stack.push("t"+count);
                count++;
            }
            else
            {
                stack.push(c+"");
            }
        }

    }
}
/*
code@code-Aspire-A515-51G:~/Pictures/code/quad$ javac Quad.java
code@code-Aspire-A515-51G:~/Pictures/code/quad$ java Quad
Enter the valid string 
abc*d+e-
string-1
| Operator | op1 | op2 | result |
|     *    |  b  |  c  |   t1   |
|     +    |  t1  |  d  |   t2   |
|     -    |  t2  |  e  |   t3   |
*/
