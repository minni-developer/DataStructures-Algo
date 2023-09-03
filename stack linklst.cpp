#include <iostream>
using namespace std;
int count=0;
class Node
{
public:
	int data;
	Node *next;
};
class Linkedlist
{
private:
	Node *first;
	Node *last;
	Node *top;
public:
	Linkedlist()
	{
		first = NULL;
		top=NULL;
	}
	
	void push(int x)
	{
		Node *n = new Node;
		n->data = x;
		n->next = NULL;
		
		if (first==NULL)
		{
			first=n;
			top=first;
		}
		else 
		{
			n->next=first;
			first=n;
			top=first;
		}
		++count;
	}

	void pop()
	{
		if(first==NULL)
		{	cout<<"List is Empty \n";	}
		else
		{	Node *p=first;
			first=first->next;
			top=first;
			cout<<" Deleted : "<<p->data<<endl;
			delete p;
		}
		count--;
	}
		
	void Top()
	{
		if (first==NULL)
	{	cout<<"NULL \n";	}	
	else 
	{
		cout<<" Top : "<<top->data<<endl;
	}	
	}
	
	void Empty()
	{
		if (first==NULL)
		{
			cout<<" True \n";
		}
		else 
			cout<<" False \n";
	}

	void display()
	{
	if (first==NULL)
	{	cout<<"List is Empty \n";	}	
	else 
	{
		Node *p=first;
		while(p!=NULL)
		{
			cout<<p->data<<" -> ";
			p=p->next;
		}
		cout<<" NULL \n";
	}
	
	}
	
};

int main()
{
				Linkedlist l;

		int val = 0;
		int choice = 0;

		do
		{
		
	cout << "  1. Push an Element " << endl;
	cout << "  2. Pop an Element " <<endl;
	cout << "  3. Check if Empty? " <<endl;
	cout << "  4. Display Top " <<endl;
	cout << "  5. Display List  " << endl;
	cout << "  9. **Exit Program** " << endl;
		cin >> choice;

			switch ( choice )
		{
			case 1:
			// INSERT
    cout << " Enter element to insert : " << endl;
	cin >> val;
	l.push(val);
	
			break;
			
	case 2:
			//DELETE
	l.pop();
			break;

	case 3:
			//EMPTY
	l.Empty();
			break;
			
	case 4:
			//PEEK
	l.Top();
			break;
			
	case 5:
			//DISPLAY
	l.display();
			break;
	case 9:
			// EXIT
			exit(0);
			break;
	}
	
}
	while(choice<=9);
	return 0;	
	
}