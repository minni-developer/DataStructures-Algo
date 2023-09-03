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
	
		void insert_Start(int x)
	{
		Node *n = new Node;
		n->data = x;
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
	
	void insert_End(int x)
	{
		Node *n=new Node;
		n->data=x;
		n->next=NULL;//new node
		
		if (first==NULL)
		{
			first=n;
			last=n;
		}
		else 
		{
			last->next=n;
			last=n;
		}
		count++;
	}
	
	void delete_Start()
	{
		if(first==NULL)
		{	cout<<"List is Empty \n";	}
		else
		{	Node *p=first;
			first=first->next;
			cout<<" Deleted : "<<p->data<<endl;
			delete p;
		}
		count--;
	}
	
	void delete_End()
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

	void search(int key)
	{
		Node *p=first;
		int i=1;
			while(p->next!=NULL)
			{
				if (p->data==key)
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
	
	void insert_Sort(int val)
	{   
		int x;
		 Node *q=NULL;
		 Node *p = first; 
		 Node *s = new Node;

		s->data = val;
		s->next = NULL;

		if ( first == NULL )
		  first = s;  
		else
			{ while ( p!= NULL && p->data < val )
		{   q = p;
			p = p->next;
		}
		if ( p == first ) 
		{   s->next = first;
			first = s;
		}
		else  
		{
			s->next = q->next;
			q->next = s;
		}
	} 	cout << " LIST AFTER INSERTION : " << endl;
		display();
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
		Linkedlist l,ls;

		int val = 0;
		int pos=0;
		int choice = 0;

		do
		{
		
	cout << "  1. Insertion at Start " << endl;
	cout << "  2. Insertion at End " << endl;
	
	cout << "  3. Deletion at Start " <<endl;
	cout << "  4. Deletion at End " <<endl;

	cout << "  5. Searching an Element " << endl;
	cout << "  6. Insert in sorted list " << endl;
	cout << "  7. Display Simple  List  " << endl;
	cout << "  8. Display Sorted List  " << endl;
	cout << "  9. **Exit Program** " << endl;
		cin >> choice;

			switch ( choice )
		{
			case 1:
			// INSERTION START
    cout << " Enter element to insert : " << endl;
	cin >> val;
	l.insert_Start(val);
			break;
			
	case 2:
			//INSERT END
	cout << " Enter element to insert : " << endl;
	cin >> val;
	l.insert_End(val);
			break;

	case 3:
			// DELETION AT START
	l.delete_Start();
			break;
	break;

	case 4:
			//  DELETION AT END
	l.delete_End();
			break;
	break;
	
	case 5:
			// SEARCHING
	cout << " Enter element to search : " ;
	cin >> val;
	l.search(val);
			break;
	break;
	
	case 6:
			// INSERT IN SORTED LINKLIST
	cout << " Enter element to insert : " ;
	cin >> val;
	ls.insert_Sort(val);
			break;
	break;
	
	case 7:
			// DISPLAY SIMPLE LIST
	l.display();
			break;
	break;
	
	case 8:
			// DISPLAY SORTED
	ls.display();
			break;
	break;
	
	case 9:
			// EXIT
			exit(0);
			break;
	break;
		
		}
	}
	
	while(choice!=9);
}