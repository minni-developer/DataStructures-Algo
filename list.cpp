#include <iostream>
using namespace std;

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

	void InsertAtBeg ( int x )
	{
		Node *t = new Node;
		t->data = x;
		t->next = NULL;
		
		if (  first == NULL )	
			first = last = t;

		else
		{
			t->next = first;
			first = t;
		}

	}

	void insertAtLast ( int x )
	{
		Node *t = new Node;
		t->data = x;
		t->next = NULL;

		if (  first == NULL ) 
			first = last = t;
		else
		{
			last->next = t;
			last = t;
		}
	}

	void InsertAtInd ( int ind )
	{
		Node *p = first;
		Node *t = new Node;
		t->data = 21;
		t->next = NULL;

		if ( ind <= 1 )
        	first = last = t;
		else
	{
		for ( int i = 0; i < ind-1; i++ )
		{  p = p->next;  }
		t->next = p->next;
		p->next = t;

	}
	}
	int deleteBeg ()
	{
		Node *p; 
		p= first; 

		int x = -1;
		if ( p == NULL )
			cout << " LIST IS EMPTY " << endl;
		else
		{
			x = p->data;
			first = first->next;
			delete p;
		}
		return x;
	}

	int deleteAtInd ( int ind )
	{
		Node *p = first; Node *q = NULL;

		int x = -1;

		if ( p == NULL )
			cout << " LIST IS EMPTY " << endl;
		else
   {
	   if ( ind == 1 )
		   deleteBeg();
	   else
	   {
		   for ( int i = 0; i < ind-1 && p != NULL; i++ )
		   {
			   q = p;
			   p = p->next ;
		   }
		if ( p != NULL )
		{
			x = p->data;
			q->next = p->next;
			delete p;
		}
		else
			deletionAtEnd();
	   }
		}
	   
	   return x;
	   }

	 int deletionAtEnd ()
	 {
		 Node *p = first; Node *q = NULL;

		int x = -1;

		 if ( p == NULL )
			cout << " LIST IS EMPTY " << endl;
		 else
		 {   
			 while ( p->next != NULL )
			 {  q = p;
				 p = p-> next;
			 }
			 x = p->data;
		q->next = NULL;
		delete p;
		 }
		 return x;
	 }

	 Node* Search ( int item )
	 {
		 Node *p = first;
		 Node *loc = 0;

		 while ( p-> data != item )
		 {
			 if ( p->next == NULL  )
			  { loc = NULL;
			 
			 cout<<"Search is unsuccessfull"<<endl;
			 return loc;}

			 else
        	{ p = p->next;
			 loc = p;
		 }
		 }

		 cout << " SEARCH IS SUCCESSFUL " << endl;
		 return loc;
		}

	void display()
	{ 
		if ( first == NULL )
			cout << " LIST IS EMPTY " << endl;
		else
		cout << " The values in the list are :" << endl;
		Node *p = first;
		while ( p != NULL )
		{
			cout << p->data << " " ;
			p = p->next;
		}
		cout << endl;
	}

	void SortedInsertion()
	{   
		int val;
		 Node *q; Node *t;
		 Node *p = first; 
		t= NULL;   q = NULL;

		cout << " Enter the value that u want to insert " << endl;
		cin >> val;
		t = new Node;

		t->data = val;
		t->next = NULL;

		if ( first == NULL ) //means if it is the very first node that is going to be created
		  first = t;  
		else
			{ while ( p!= NULL && p->data < val )
		{   q = p;
			p = p->next;
		}
		if ( p == first ) // means this node is going to be inserted in left before the very first node ( at beginning)
		{   t->next = first;
			first = t;
		}
		else   // means it is going to be inserted in between or at end
		{ t->next = q->next;
		q->next = t;
		}
	} 	cout << " THE LIST AFTER INSERTION IS : " << endl;
		display();
	}
	
	bool isSorted()
	{ 
		Node *p = first;
	    int x = INT_MIN; // this is the minimum integer in c++
		// its like we are storing minimum integer...
		
		if ( p == NULL )
			cout << " LIST IS EMPTY " << endl;

		while ( p != NULL )
		{
			if ( p->data < x )
			{   cout << " LIST IS NOT SORTED " << endl;
				return false;  // means it is not sorted
			}
			else
	{ // if data is greater than x then we will store that data in x and now will compare it with next data
			x = p->data; 
			p = p->next;
			}
		}
		cout << " LIST IS SORTED " << endl;
		return true;   // means it is sorted
	}
};

	int main ()
	{
	//	Node n;
		Linkedlist l;
		Linkedlist s;

		int val = 0;
		int ind = 0;
		int select = 0;
		
		
	/*cout << "  Enter 1 for insertion at beginning    " << endl;
	cout << "  Enter 2 for insertion at end   " <<endl;
	cout << "  Enter 3 for insertion  at any index " << endl;
	cout << "  Enter 4 for sorted insertion " << endl;
	cout << "  Enter 5 to display unsorted linked list " << endl;
	cout << "  Enter 7 to display sorted linked list " << endl;
	cout << "  Enter 8 for deletion from beginning  " << endl;
	cout << "  Enter 7 for deletion at any index  "  << endl;
	cout << "  Enter 9 for deletion at end " << endl;
	cout << "  Enter 10 for searching in unsorted list  " << endl;
	cout << "  Enter 11 for if link is sorted " << endl;
    cout << "  ||| and enter 0 to stop ||| "  << endl;
	*/

		do
		{
			// cout << endl;
			//cout << " FOLLOW TH INSTRUCTIONS AND SELECT A NUMBER FOR EACH SPECIFIC TASK " << endl;
			//cout << endl;
			//cin >> select;

	cout << "  Enter 1 for insertion at beginning    " << endl;
	cout << "  Enter 2 for insertion at end   " <<endl;
	cout << "  Enter 3 for insertion  at any index " << endl;
	cout << "  Enter 4 for sorted insertion " << endl;
	cout << "  Enter 5 to display unsorted linked list " << endl;
	cout << "  Enter 6 to display sorted linked list " << endl;
	cout << "  Enter 7 for deletion from beginning  " << endl;
	cout << "  Enter 8 for deletion at any index  "  << endl;
	cout << "  Enter 9 for deletion at end " << endl;
	cout << "  Enter 10 for searching in unsorted list  " << endl;
	cout << "  Enter 11 for if link is sorted " << endl;
    cout << "  ||| and enter 0 to stop ||| "  << endl;

	cout << " FOLLOW TH INSTRUCTIONS AND SELECT A NUMBER FOR EACH SPECIFIC TASK " << endl;
			cout << endl;
			cin >> select;


			switch ( select )
		{
			case 1:
			// INSERTION AT BEGINNING 
    cout << " Enter value that u want to insert " << endl;
	cin >> val;
	l.InsertAtBeg(val);

	break;

		case 2:
			// INSERTION AT END
      cout << " Enter value that u want to insert " << endl;
	cin >> val;
	l.insertAtLast(val);

	break;

		case 3:
			// INSERTION AT ANY INDEX
			cout << " Enter the index " << endl;
			cin >> ind;
	l.InsertAtInd(ind);
	break;

		case 4:

			cout << " AFTER SORTING " << endl;
			s.SortedInsertion();
			break;

		case 5:
			// TRAVERSING IN UNSORTED
			l.display();
			break;


		case 6:
			// TRAVERSING IN SORTED 
			s.display();
			break;

		case 7:
			// DELETION AT BEGIINING

			l.deleteBeg();
			break;

		case 8:
			// DELETION AT ANY INDEX
			cout << " Enter the index of node which u wanna delete " << endl;
			cin >> ind;
			l.deleteAtInd(ind);
			break;

		case 9:
			// DELETION AT END
			l.deletionAtEnd();
		break;

		case 10:
			// SEARCHING 
			cout << " Enter the item that u want to find " << endl;
			cin >> val;

			l.Search(val);
			break;

		case 11:
			// If is sorted
			s.isSorted();
			}

		} while ( select != 0 );

		cout << " |||| PROGRAM ENDED |||| " << endl;

  return 0;

	}

