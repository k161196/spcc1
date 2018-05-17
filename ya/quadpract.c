#include <stdio.h>
#include<string.h>

#define MAX 20

char op1,op2;
int i;
char stack[MAX];
char x='A';

int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

char push(){
    char data;
    if(!isempty()){
        data=stack[top];
        top=top-1;
        return data;
    }
}

int isfull(){
    if(top==MAX){
        return 1;
    }
    else
        return 0;
}
void push(char data){
    if(!isfull()){
        top=top+1;
        stack[top]=data;
    }
}


int main(void) {
    char arr[MAX];
    printf("Enter your potfix expr:");
    scanf("%s",arr);
    printf("\noperator\t\top1\t\top2\t\tresult")
    for(i=0;i<strlen(arr);i++){
        if(!(arr[i]==*||arr[i]==-||arr[i]==/||arr[i]==+)){
            push(arr[i]);
        }
        else{
            op2=pop();
            op1=pop();
            printf("\n%c",arr[i]);
            printf("\t\t%c",op1);
            printf("\t\t%c",op2);
            push(x);
            printf("\n%c",x++);
            
        }
    }
	return 0;
}

/*
Enter your potfix expr:abc*d/+e-
operator		op1		op2		result
*		b		c		A
/		A		d		B
+		a		B		C
-		C		e		D
*/