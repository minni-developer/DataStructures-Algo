#include <iostream>
using namespace std;


class node{
	public:
	int data;
	node* next;
	node(int data){
		this->data=data;
		next=NULL;
	}
};
class linklist {
	node* head=NULL;
	public:
		void insertionatlast(int data){
			node* newnode=new node(data);
			if(head==NULL){
				head=newnode;
			}
			else{
				node* ptr;
				ptr=head;
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=newnode;
				
			}
		}
		void insertionatbeg(int data){
			node* newnode= new node(data);
			newnode->next=head;
			head=newnode;
		}
		void deletionfirst()
		{
			node* ptr = head;
			head = ptr->next;
		}
		void deleteatlast()
		{
			node* ptr = head;
			if(ptr->next==NULL){
			   head=NULL;
			}
			else{
			while( ptr->next->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = NULL;
		}
			
		}
		
		void finding (int data)
		{
			node* ptr;
			ptr = head;
			int count= 1; 
			while(ptr->data != data && ptr->next != NULL)
			{
				
				ptr = ptr->next;
				count++;
			}
			if(ptr->data == data )
			{
				cout << "/nITEM FOUND AT NODE NUMBER "  << count << endl;
			}
			else
			cout << "ITEM NOT FOUND " << endl;
			
			
		}
		
		void print(){
			node* ptr;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<< " ";
				ptr=ptr->next;
			} cout << endl;
		}
		void insert_Sort(int val)
	{   
	//	int x;
		 node *q=NULL; 
		node *s= new node;
		 node *p = head; 

		s = NULL;

		s->data = val;
		s->next = NULL;

		if ( first == NULL )
		  first = s; 
		else
			{ while ( p!= NULL && p->data < val )
		{   q = p;
			p = p->next;
		}
		if ( p == head ) 
		{   s->next = head;
			head = s;
		}
		else  
		{s->next = q->next;
		q->next = s;
		}
	} 	cout << " LIST AFTER INSERTION : " << endl;
		print();
	}	
		
};
int main()
{
	linklist l1;
	int choice;
	int data;
	cout << "ENTER 1 INSERTION AT BEG"<< endl;
	cout << "ENTER 2 FOR INSERTION AT END" << endl;
	cout << "ENTER 3 FOR DISPLAY" << endl;
	cout << "ENTER 4 FOR DELETION AT BEG" << endl;
	cout << "ENTER 5 FOR DELETION AT END " << endl;
	cout << "ENTER 6 FOR SEARCHING " << endl;
	cout << "ENTER 0 TO END PROGRAM" << endl;
	cin>>choice;
	do{
		switch(choice){
			case 1:
				cout<<"Enter";
				cin>>data;
				l1.insertionatbeg(data);
				break;
			case 2:
				cout<<"Enter";
				cin>>data;
				l1.insertionatlast(data);
				break;
			case 3:
				l1.print();
				
			break;
			
			case 4:
				cout << "\nITEM DELETED\n";
				l1.deletionfirst();
				break;
				
			case 5:
				cout << "\n ITEM DELETED AT END\n";
				l1.deleteatlast();
				break;
				
			case 6:
				cout << "ENTER ELEMENT FOR SEARCH " << endl;
				cin >> data;
				l1.finding(data);
				break;
		}
		cout << "ENTER 1 INSERTION AT BEG"<< endl;
	cout << "ENTER 2 FOR INSERTION AT END" << endl;
	cout << "ENTER 3 FOR DISPLAY" << endl;
	cout << "ENTER 4 FOR DELETION AT BEG" << endl;
	cout << "ENTER 5 FOR DELETION AT END " << endl;
	cout << "ENTER 0 TO END PROGRAM" << endl;
		cin>>choice;
	}while(choice!=0);
	
}
