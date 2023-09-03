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
public:
	Linkedlist()
	{
		first = NULL;
		last = NULL;
	}
	
	void insert(int val)
	{
		Node *n = new Node;
		n->data = val;
		n->next = NULL;
		
		if (first==NULL)
		{
			first=n;
			last=n;
		}
		else 
		{
			n->next=first;
			first=n;
		}
		++count;
	}
	
	void deletion()
	{
		Node *p=first; 
		Node *q=NULL;
		if(first==NULL)
		{	cout<<"List is Empty \n";
			return;	}

		if(first->next==NULL)
		{
			cout<<" Deleted : "<<p->data<<endl;
			first=NULL;
			last=NULL;
			delete p;
		}
		else
		{
			while(p->next!=NULL)
			{	
				q=p;
				p=p->next;
			}
			cout<<" Deleted : "<<p->data<<endl;
			last=q;
			
			last->next=NULL;
			delete p;
		}
		count--;
	}
	
	void search(int val)
	{
		Node *p=first;
		int i=1;
			while(p->next!=NULL)
			{
				if (p->data==val)
				{
					cout<<" FOUND at :"<<i<<endl;
					return;
				}
				else
				{
					p=p->next;
				}
				++i;
			}
			cout<<" NOT FOUND...! \n";
			return;	
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
	
	void Peek()
	{
		if (first==NULL)
	{	cout<<"NULL \n";	}	
	else 
	{
		cout<<" Peek : "<<last->data<<endl;
	}	
	}
	
	void Empty()
	{
		if (first==NULL)
		{
			cout<<" False \n";
		}
		else 
			cout<<" True \n";
	}
};

int main()
{
			Linkedlist l;

		int val = 0;
		int choice = 0;

		do
		{
		
	cout << "  1. Insert an Element " << endl;
	cout << "  2. Delete an Element " <<endl;
	cout << "  3. Search an Element " << endl;
	
	cout << "  4. Check if Empty? " <<endl;
	cout << "  5. Display Peek " <<endl;
	
	cout << "  6. Display List  " << endl;
	cout << "  9. **Exit Program** " << endl;
		cin >> choice;

			switch ( choice )
		{
			case 1:
			// INSERT
    cout << " Enter element to insert : " << endl;
	cin >> val;
	l.insert(val);
			break;
			
	case 2:
			//DELETE
	l.deletion();
			break;
			
	case 3:
			//SEARCH
	cout << " Enter element to search : " << endl;
	cin >> val;
	l.search(val);
			break;
			
	case 4:
			//EMPTY
	l.Empty();
			break;
			
	case 5:
			//PEEK
	l.Peek();
			break;
			
	case 6:
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