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
		last = first;
	}
    void insert_Start(int val)
	{
		Node *n = new Node;
		n->data = val;
		n->next = NULL;
		Node *temp=first;
		
		if (first==NULL)
		{
			n->next=n;
			first=n;
			return;
		}	
		
		while(temp->next!=first)
		{
			temp=temp->next;
		}
		temp->next=n;
		n->next=first;
		first=n;
		
		++count;
	}
	void insert_End(int val)
	{
		Node *n=new Node;
		n->data=val;
		n->next=NULL;
		Node *temp=first;

		if(first==NULL)
		{
			insert_Start(val);
			return;
		}

		while(temp->next!=first)
		{
			temp=temp->next;
		}
		temp->next=n;
		n->next=first;
		count++;
	}
	void delete_Start()
	{	
		Node *p=first;
		
		if(first==NULL)
		{	cout<<"List is Empty \n";
			return;	}
		else if (first->next==first)
		{
			cout<<" Deleted : "<<p->data<<endl;
			first=NULL;
			delete p;
			count--;
			return;
		}
		else
	  {
		while(p->next!=first)
		{
			p=p->next;
		}
		cout<<" Deleted : "<<first->data<<endl;
		Node *q=first;
		p->next=first->next;
		first=first->next;
		delete q;
		count--;
  	  }
	}
	
	void delete_End()
	{
		Node *p=first;
		
		if(first==NULL)
		{	cout<<"List is Empty \n";
			return;	}
		else if (first->next==first)
		{
			cout<<" Deleted : "<<p->data<<endl;
			first=NULL;
			delete p;
			count--;
			return;
		}
		else
		{
			Node *q=NULL;
			while(p->next!=first)
			{
				q=p;
				p=p->next;
			}
			q->next=first;
			cout<<" Deleted : "<<p->data<<endl;
			delete p;
			count--;	
		}
		
	}
	
	void search(int val)
	{
		if (first==NULL)
		{	cout<<"List is Empty \n";	}	
		else
		{
			Node *p=first;
			int i=1;
			do
			{ 
				if (p->data==val)
				{
					cout<<" Found..! \n";
					return;
				}
				p=p->next;
				i++;
			}
			while(p!=first);
			if (i>=count)
			{
				cout<<" Not Found...! \n";
			}
		}	
	
	}
	
	void display()
	{
		if (first==NULL)
		{	cout<<"List is Empty \n";	}	
		else 
		{
		Node *p=first;
		do
		{
			cout<<p->data<<" -> ";
			p=p->next;
		}
		while(p!=first);
		cout<<" NULL \n";
		}
	}
};
int main()
{
	Linkedlist l;
	int choice;
	int val=0;
do {	
	cout << "  1. Insertion at Start " << endl;
	cout << "  2. Insertion at End " << endl;
	cout << "  3. Deletion at Start " <<endl;
	cout << "  4. Deletion at End " <<endl;
	cout << "  5. Search an Element " << endl;
	cout << "  6. Display the List  " << endl;
	cout << "  7. **Exit Program** " << endl;
		cin >> choice;

	
	switch(choice)
	{
	case 1:
		cout<<" Enter a value to insert : ";
		cin>>val;
		l.insert_Start(val);
		
		break;
		
	case 2:
		cout<<" Enter a value to insert : ";
		cin>>val;
		l.insert_End(val);
		
		break;
		
	case 3:
		l.delete_Start();
		break;
		
	case 4:
		l.delete_End();
		break;
		
	case 5:
		cout<<" Enter a value to Search : ";
		cin>>val;
		l.search(val);
		break;
		
	case 6:
		l.display();
		break;
		
	case 7:
			// EXIT
			exit(0);
			break;
	break;
		
    }	
  }
	while(choice<=7);	
		return 0;
}
