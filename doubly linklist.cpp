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
public:
	Linkedlist()
	{
		first = NULL;
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
				return;
			}
		else 
		{
			n->next=first;
			first->prev=n;
			first=n;
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
			return;
		}
		else 
		{
			Node *p=first;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=n;
			n->prev=p;
		}
	}
	
	void insertion_sort(int val)
	 {
	 	Node *p=first;
	 	Node *q=NULL;

	 		
	 		if (val<p->data)
	 		{
	 			insetion_Start(val);
				return;	
			}
	 		else if (val>p->data)
	 		{	
	 			while (p->data<val)
	 			{
	 				q=p;
	 				p=p->next;
				 }
				if (p->next!=NULL)
				{	
					
					Node *n = new Node;
					n->data = val;
					n->next = NULL;
					n->prev = NULL;
					
					p=p->next;
					n->next=q->next;
					q->next=n;
					n->prev=q;
					p->next=n;
				}
				else  
				{
					insertion_End(val);
					return;
				}
			 }
	 }
	 
	 
	void deletion_Start()
	{
		if(first->next==NULL)
		{
			cout<<" deleted : "<<first->data<<endl;
			first=NULL;
			return;
		}
		else 
		{
			Node *p=first;
			cout<<" deleted : "<<p->data<<endl;
			first=first->next;
			first->prev=NULL;
			delete p;
			return;
		}
	}
	
	void deletion(int pos)
	{
		if(first->next==NULL)
		{
			cout<<" deleted : "<<first->data<<endl;
			first=NULL;
			return;
		}
		if(pos==1)
		{
			deletion_Start();
		}
		Node *p=first;
		int count=1;
		
		while (p!=NULL && count!=pos)
		{
			p=p->next;
			count++;
		}
		p->prev->next=p->next;
		if (p->next!=NULL)
		{
			p->next->prev=p->prev;	
		}
		cout<<" deleted : "<<p->data<<endl;
		delete p;
	}
	

	void display()
	{
		Node *p=first;
		
		while(p!=NULL)
		{
			cout<<p->data<<" -> ";	
			p=p->next;
		}	cout<<" NULL \n";
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
	cout << "  4. Deletion at Start " <<endl;
	cout << "  5. Insertion in Sorted " <<endl;
	cout << "  6. Display Simple List  " << endl;

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
			//DELETION 
	l.deletion_Start();
			break;
		
	case 5:
			//SORTING
	l.insertion_sort(val);
	cout << " Enter element to insert " << endl;
	cin >> val;
			break;	
	case 6:
			//DISPLAY
	l.display();
			break;
	}
}
while(choice<=6);
}