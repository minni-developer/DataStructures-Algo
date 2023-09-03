#include<iostream>
#include<cstring>
using namespace std;
int top=-1;            

void push(char nam[],char pushName[])
	{
		while(nam[++top]!='\0')
		{
			pushName[top]=nam[top];
		}
	}
void pop_str(char nam[],char revName[])
	{
		int temp=0 ,pop=top;
		if(pop==-1)
			cout<<"array is empty"<<endl;
		else
		{
			while(--pop>=0)
			{
				revName[temp++] = nam[pop];
			}
		}
	}
int main(){
	char name[25] , pushname[25] , revName[25];
	bool Pelindrome=true;
	cout<<"enter your name: ";
	cin.getline(name,24);
	push(name,pushname);						//	pushing cahrters to new array
	pop_str(pushname,revName);	               //  	pop charters and assinging to reverse name
	cout<<"\nName: "<<pushname<<"\tRev: "<<revName<<endl;
	for(int tem=0 ; pushname[tem] != '\0' ; tem++) 
	{	
		if(pushname[tem]!=revName[tem])       // for word to word compairson
		{
			Pelindrome=false;
			cout<<"\n\t Not Pelindrome\n";
			break;
		}
	}
	if(Pelindrome==true)
	cout<<"\n\t Pelindrome\n";		
	return 0;
}
