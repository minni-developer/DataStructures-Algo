#include <iostream>
using namespace std;
int count=0;
class Node
{
public:
	int data;
	Node *next;
	Node *prev;
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
	
	void insetion_Start(int x)
	{
		Node *n = new Node;
		n->data = x;
		n->next = NULL;
		n->prev = NULL;
		
		if (first==NULL)
			{
				first=n;
				last=n;
				count++;
				return;
			}
	
		else 
		{	 if(first->next==NULL) 
			{	last=first;	}
			
			n->next=first;
			first->prev=n;
			first=n;
			count++;
		}
	}
	
	void insertion_End(int x)
	{
		Node *n = new Node;
		n->data = x;
		n->next = NULL;
		n->prev = NULL;	
		
	if (first==NULL)
		{
			first=n;
			last=n;
			count++;
			return;
		}
		else 
		{	 if(first->next==NULL) 
			{	last=first;	}
			
			n->prev=last;
			last->next=n;
			last=n;
			count++;
		}
	}
		
	void deletion(int pos)
	{	if (first==NULL)
			{	cout<<"List is Empty \n";
				return;
			}
		if (pos>count)
		{	cout<<"Invalid Position \n";
			return;	}
	

		if(first->next==NULL)
		{
			cout<<" deleted : "<<first->data<<endl;
			first=NULL;
			last=NULL;
			count--;
			return;
		}
		if(pos==1)
		{
			Node *p=first;
			cout<<" deleted : "<<p->data<<endl;
			first=first->next;
			first->prev=NULL;
			delete p;
			count--;
			return;
		}
		else {
	
		Node *p=first;
		int count=1;
		
		while (p!=NULL && count!=pos)
		{
			p=p->next;
			count++;
		}
		p->prev->next=p->next;
		
		if (p->next!=NULL)
		{	p->next->prev=p->prev;	}
		
		cout<<" deleted : "<<p->data<<endl;
		delete p;
		count--;
		}
	}
	void display()
	{
		Node *p=first;
		
		while(p!=NULL)
		{
			cout<<p->data<<" -> ";	
			p=p->next;
		}	cout<<" NULL \n";
		cout<<"Count of List :"<<count<<endl;
	}
	
	void reverse()
	{
		Node *p=last;
		
		while(p!=NULL)
		{
			cout<<p->data<<" <-";	
			p=p->prev;
		}	cout<<" NULL \n";
		cout<<"Count of List :"<<count<<endl;
	}
	
};
int main()
{
		Linkedlist l;
		int pos=0;
		int val = 0;
		int choice = 0;

		do
		{
		
	cout << "  1. Insertion at Start " << endl;
	cout << "  2. Insertion at End " << endl;
	cout << "  3. Deletion at Position" <<endl;
	cout << "  4. Display Simple List  " << endl;
	cout << "  5. Display Reverse List  " << endl;
		cin >> choice;

	switch ( choice )
	{
	case 1:
			// INSERTION START
    cout << " Enter element to insert " << endl;
	cin >> val;
	l.insetion_Start(val);
			break;
			
	case 2:
			//INSERT END
	cout << " Enter element to insert " << endl;
	cin >> val;
	l.insertion_End(val);
			break;
			
	case 3:
			//DELETION 
	cout << " Enter position to delete " << endl;
	cin >> pos;
	l.deletion(pos);
			break;

	case 4:
			//DISPLAY
	l.display();
			break;
			
	case 5:
			//REVERSE
	l.reverse();
			break;
	}
}
while(choice<=6);
}