import java.io.*;
import java.util.*;
public class Parser{
static HashMap<String,String> acctyp;
public static void main(String args[])throws IOException{
Scanner sc=new Scanner(System.in);

ArrayList<String> stack=new ArrayList<String>();
stack.add("$");
stack.add("E");

//entering entries in table
HashMap<String, HashMap<String,String>> gens = new HashMap<String,HashMap<String,String>>();
acctyp = new HashMap<String,String>();
acctyp.put("i","TA");
acctyp.put("(","TA");
gens.put("E", acctyp);
acctyp = new HashMap<String,String>();
acctyp.put("+","+TA");
acctyp.put(")","epsilon");
acctyp.put("$","epsilon");
gens.put("A", acctyp);
acctyp = new HashMap<String,String>();
acctyp.put("i","FB");
acctyp.put("(","FB");
gens.put("T", acctyp);
acctyp = new HashMap<String,String>();
acctyp.put("+","epsilon");
acctyp.put("*","*FB");
acctyp.put(")","epsilon");
acctyp.put("$","epsilon");
gens.put("B", acctyp);
acctyp = new HashMap<String,String>();
acctyp.put("i","i");
acctyp.put("(","(E)");
gens.put("F", acctyp);

System.out.println("Enter the string to be checked");
String s=sc.next();
int flag=1;
int point=0;

while(stack.size()>0){

String lhs=stack.get(stack.size()-1);
//System.out.println("point is "+point);
String ans=gens.get(lhs).get(s.charAt(point)+"");

if(ans==null){										//null
flag=0;
System.out.println("invalid string");
break;
}


if(ans.equals("epsilon"))							//epi
stack.remove(stack.size()-1);
//System.out.println("stacktop "+lhs);
System.out.println("new production -- "+ans);


if(lhs.charAt(0)>='A'&&lhs.charAt(0)<='Z'){				//pop push
if(!ans.equals("epsilon")){
System.out.println("popped --"+stack.get(stack.size()-1));
//pop top element
stack.remove(stack.size()-1);
//insert new char
}
for(int k=ans.length()-1;k>=0;k-- )
{
if(!ans.equals("epsilon")){
stack.add(ans.charAt(k)+"");
System.out.println("pushed-- "+ans.charAt(k));}
}
}



if(s.charAt(point)==(stack.get(stack.size()-1)).charAt(0)){						//match found
//pop
stack.remove(stack.size()-1);
//move to next element
point++;
//System.out.println("valid character found");
}
else if(stack.get(stack.size()-1).charAt(0)>='A'&&stack.get(stack.size()-1).charAt(0)<='Z'){//go tobtable
System.out.println("go to table");
}
else{
if(!ans.equals("epsilon")){											//not even epi
System.out.println("Invalid String ");
flag=0;
break;
}
}
}
if(flag==1)
System.out.println("Valid input String");
}
}
