#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class stack 
{
char stk[20];
int top=-1;
public:

void push(char oper)
{
    if(top==20-1)
    {
        cout<<"stack is full!! "<<endl;
    }
   
    else
    {
        top++;
        stk[top]=oper;
    }
}
char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"stack is empty!! "<<endl;
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int priority ( char alpha )
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }
 
    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }
 
    if(alpha == '^')
    {
        return(3);
    }
 
    return 0;
}
string convert(string infix)
{
    int i=0;
    string postfix = "";   
    while(infix[i]!='\0')
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z'|| infix[i]>='0'&& infix[i]<='9')          
        {
            postfix.insert(postfix.end(),infix[i]);
            i++;
        }       
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')
        {
            push(infix[i]);
            i++;
        }        
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')
        {
            if(infix[i]==')')
            {
                while(stk[top]!='(')
                {               postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i]==']')
            {
                while(stk[top]!='[')
                {
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
 
            if(infix[i]=='}')
            {
                while(stk[top]!='{')
                {
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                push(infix[i]);
                i++;
            }
 
            else if( priority(infix[i]) <= priority(stk[top])) {
                postfix.insert(postfix.end(),pop());
               
                while(priority(stk[top]) == priority(infix[i])){
                    postfix.insert(postfix.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])) {
                push(infix[i]);
                i++;
            }
        }
    }
    while(top!=-1)
    {
        postfix.insert(postfix.end(),pop());
    }
    cout<<"The converted postfix string is : "<<postfix; 
    return postfix;
}
float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}
int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;    //character is an operator
   return -1;   //not an operator
}
int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}
float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); //find b^a
   else
      return INT_MIN; //return negative infinity
}
float postfixEval(string postfix) {
   int a, b;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1) {
         a = stk[top];
         pop();
         b = stk[top];
         pop();
         push(operation(a, b, *it));
      }else if(isOperand(*it) > 0) {
         push(scanNum(*it));
      }
   }
   return stk[top];
}
};

int main()
{
	
	int option;
	stack s;
	 string infix, postfix;
    int cont;
    do
	{	
	cout<< "\n 1. Convert into Postfix "<<endl;
	cout<< " 2. Evluate Postfix "<<endl;
	cout<< " 0. Exit Program "<<endl;
	cin>>option;
    switch (option)
    {
	
	case 1:
		{
    cout<<"Enter the infix expression : "; 
    cin>>infix;
    postfix = s.convert(infix);
    break;
}
case 2:
	{
	cout<<" Enter the infix expression : "; 
    cin>>infix;
    postfix = s.convert(infix);
    cout << "\n Value after Evaluation : "<<s.postfixEval(postfix);
    break;
}
case 3:
	{
		system("cls");
	}
}
}
while (option!=0);
}
