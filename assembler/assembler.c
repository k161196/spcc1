#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define RX 1
struct MOT_TABLE{
char op[4];
int frmt;
int len;
}m[10];
struct SYM_TABLE{
char sym[20];
int add;
int len;
char rel;
int val;
}s[20];
struct LIT_TABLE{
char sym[20];
int add;
int len;
char rel;
}l[20];
void initMOT(){
strcpy(m[0].op,"L");
m[0].frmt=RX;
m[0].len=4;
strcpy(m[1].op,"A");
m[1].frmt=RX;
m[1].len=4;
strcpy(m[2].op,"ST");
m[2].frmt=RX;
m[2].len=4;
}
int main(){
char *POT[6]={"USING","START","EQU","DS","END","DC"};
initMOT();
int sCount=0,lCount=0,number=0,location=0,nextline=0,slen=0,x;
size_t len = 0;
ssize_t read;
char * str;
char *line;
int i,flag=0;
FILE *file;
file = fopen( "CODE.ASM" , "r");
if(file){
while ((read = getline(&line, &len, file)) != -1){
nextline=0;
str=strtok(line," ");
while(str!=NULL){
flag=0;
if((str[0]>57 || str[0]<48) && str[0]!=44)
{
for(i=0;i<6 && flag!=1;i++)
{
if(strcmp(str,POT[i])==0)
{
flag=1;
if(strcmp(str,"START")==0){
str=strtok(NULL," ");
location=atoi(str);
nextline=1;
}
else if(strcmp(str,"USING")==0){
nextline=1;
}
else if(strcmp(str,"EQU")==0){
nextline=1;
str=strtok(NULL," ");
number=atoi(str);
s[sCount-1].val=number;
s[sCount-1].rel='A';
}
else if(strcmp(str,"DC")==0){
nextline=1;
str=strtok(NULL," ");
if(str[0]=='F')
{
location=location+4;
s[sCount-1].len=4;
}
else if(str[0]=='I')
{
location=location+2;
s[sCount-1].len=2;
}
number=atoi(&str[2]);
s[sCount-1].val=number;
s[sCount-1].rel='A';
}
else if(strcmp(str,"DS")==0){
nextline=1;
str=strtok(NULL," ");
slen=strlen(str);
if(str[len-1]=='F')
{
number=0;
for(i=0;i<len-1;i++)
number=number*10+ atoi(&str[i]);
}
else
number=atoi(str);
s[sCount-1].val=number;
s[sCount-1].rel='A';
}
}
}
for(i=0;i<3 && flag!=1;i++)
{
if(strcmp(str,m[i].op)==0)
{
flag=1;
location=location+m[i].len;
str=strtok(NULL," ");
str=strtok(NULL," ");
str=strtok(NULL," ");
if(str[0]=='=')
{
x=0;
number=strlen(str);
for(i=1;i<strlen(str);i++)
strcpy(&l[lCount].sym[x++],&str[i]);
l[lCount].sym[number-2]='\0';
l[lCount].len=4;
l[lCount++].rel='R';
}
nextline=1;
}
}
if(flag==0)
{
if(strcmp(str,"LTORG")==10)
{
for(i=0;i<lCount;i++)
{
l[i].add=location;
location=location+l[i].len;
}
}
else
{
strcpy(s[sCount].sym,str);
s[sCount].add=location;
s[sCount].val=location;
s[sCount].len=1;
s[sCount].rel='R';
sCount++;
}
}
}
if(nextline==1)
break;
else
str = strtok (NULL, " ");
}
}
}
fclose(file);
printf("\n############### SYMBOL TABLE ###############\n");
printf("\nADDRESS\tSYMBOL\tVALUE\tLENGTH\tRELOCATION\n");
for(i=0;i<sCount;i++)
printf("\n%d\t%s\t%d\t%d\t%c\n",s[i].add,s[i].sym,s[i].val,s[i].len,s[i].rel)
;
printf("\n############### LITERAL TABLE ###############n\n");
printf("\nLIT\tADDRESS\tLENGTH\tRELOCATION\n");
for(i=0;i<lCount;i++)
printf("\n%s\t%d\t%d\t%c\n",l[i].sym,l[i].add,l[i].len,l[i].rel);
printf("\n############### PASS 2 ###############\n");
int base[15];
int arg1,data,content,value,baseValue,result,j,k,use,iLength,iFormat;
char dup[100],operation[100];
for(i=0;i<=15;i++)
base[i]=-1;
location=0;
printf("\nINST\tLOC\tDATA\n\n");
file = fopen( "CODE.ASM" , "r");
if(file){
while ((read = getline(&line, &len, file)) != -1)
{
str=strtok(line," ");
while(str!=NULL)
{
flag=0;
if((str[0]>57 || str[0]<48) && str[0]!=44)
{
for(i=0;i<6 && flag!=1;i++)
{
if(strcmp(str,POT[i])==0)
{
flag=1;
if(strcmp(str,"START")==0){
str=strtok(NULL," ");
location=atoi(str);
nextline=1;
}
else if(strcmp(str,"USING")==0)
{
nextline=1;
str=strtok(NULL," ");
if(strcmp(str,"*")==0)
use=location;
else
use=atoi(str);
str=strtok(NULL," ");
str=strtok(NULL," ");
if(str[0]<57 && str[0]>48)
{
baseValue=atoi(str);
base[baseValue]=use;
}
}
}
}
for(i=0;i<3 && flag!=1;i++)
{
if(strcmp(str,m[i].op)==0)
{
flag=1;
result=0;
strcpy(operation,m[i].op);
iLength=m[i].len;
iFormat=m[i].frmt;
str=strtok(NULL," ");
if(str[0]<57 && str[0]>48)
arg1=atoi(str);
str=strtok(NULL," ");
str=strtok(NULL,"\n");
for(j=0;j<sCount;j++){
if(strcmp(str,s[j].sym)==0){
result=1;
value=s[j].val;
content=base[baseValue];
data=value-content;
}
}
for(k=0;k<lCount && result!=1;k++)
{
if(str[0]=='=')
{
x=0;
number=strlen(str);
for(i=1;i<strlen(str);i++)
strcpy(&dup[x++],&str[i]);
dup[number-1]='\0';
}
if(strcmp(dup,l[k].sym)==0)
{
result=1;
value=l[k].add;
content=base[baseValue];
data=value-content;
}
}
printf("\n%s\t%d",operation,location);
printf("\t%d,%d(%d,%d)\n",arg1,data,content,baseValue);
location=location+iLength;
nextline=1;
}
}
}
if(nextline==1)
break;
else
str = strtok (NULL, " ");
}
}
}
return 0;
}
/*
code@code-Aspire-A515-51G:~/Pictures/code/assembler$ gcc assembler.c
code@code-Aspire-A515-51G:~/Pictures/code/assembler$ ./a.out

############### SYMBOL TABLE ###############

ADDRESS	SYMBOL	VALUE	LENGTH	RELOCATION

0	KIRAN	0	1	R

16	THREE	3	4	A

20	FIVE	5	4	A

24	TEMP	1	1	A

############### LITERAL TABLE ###############n

LIT	ADDRESS	LENGTH	RELOCATION

F'5'	12	4	R

############### PASS 2 ###############

INST	LOC	DATA


L	0	1,12(0,15)

A	4	1,12(0,15)

ST	8	1,1(0,15)
*/