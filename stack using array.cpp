#include <iostream>
using namespace std;
class stack
{	int top;
	int a[5];
	public:
	stack()
	{
		top=-1;
		for (int i=0; i<5; i++)
		{
			a[i]=0;
		}	
	}
	void push(int val)
	{
		if (top==4)
		{
			cout<< "Stack is full... \n"<<endl;
		}
		else 
		{
			top++;
			a[top]=val;
		}
	}
	void pop()
	{
		if (top==-1){
			cout<< "stack is empty... "<<endl;
			cout<< "No Element to pop! \n"<<endl;
		}
		else 
		{
			int val;
			a[top] =0;
			top--;
			val=a[top];
		}
	}
	void peek()
	{
		cout<<"Peek : "<<a[top]<<endl;
	}
	void traversing()
	{
		for (int i=4; i>=0; i--)
		{
			cout<< a[i]<< " ";
			cout<< endl;
		}
	}	
};
int main ()
{
	stack s;
	int item;
	int option;
	//s.traversing();
	do
	{	cout<< "Press 1 for Push "<<endl;
		cout<< "Press 2 for pop "<<endl;
		cout<< "Press 3 for peek "<<endl;
		cout<< "Press 4 for clear "<<endl;
		cout<< "Press 5 for Displaying "<<endl;
		cout<< "Press 0 for Exit \n"<<endl;
		cin >>option;
		switch (option)
		{
			case 1:
			{
				cout<< "Enter the Number :"<< endl; 
				cin >>item;
				s.push(item);
				break;
			}
			case 2:
				{
					cout<< "Poping... "<<endl;
					s.pop();
					break;
				}
			case 3:
				{
				s.peek();
					break;
				}
			case 4:
				{
					system("cls");
					break;
				}
		    case 5:
		    	{
		    		s.traversing();
		    		break;
				}
		}
	}
	while (option !=0);
}

