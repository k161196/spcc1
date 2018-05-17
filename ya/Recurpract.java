import java.io.*;
import java.util.*;

public class Recurpract
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of Production rules:");		//enter n
		int n = sc.nextInt();

		int k = 0;
		String rule;
		String alpha=new String();

		while(k<n){															//for all n
			int flag=0;
			rule=sc.next();													//get input rule

			String[] arr = rule.split("->");								//S->Sa|b
			String left = arr[0];											//S
			String[] right = arr[1].split("\\|");							//Sa|b

			for(int i=0;i<right.length;i++){
				if(right[i].startsWith(left)){
					alpha = right[i].substring(1);							//extract alpha
					flag=1;
				}
				System.out.println("After Check for left Recursion");
				if(flag==1){
				System.out.println(left+"->"+right[1]+left+"'");			//S->bS'
				System.out.println(left+"->"+alpha+left+"'|e");				//S->aS'|e
				break;														//for for next rule
				}
				else{
				System.out.println(left+"->"+right[i]);						//A->aD
				break;														//go for next rule
				}
			}
			k++;															//go to while
		}

	}
}
