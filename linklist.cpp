#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int val)
		{
			data =val;
			next=NULL;
		}
};

void insertAtTail(node* &head,int val)
{
	node * n=new node(val);
	if(head==NULL)
	{
		head=n;
		return;
	}
	
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}

void display(node* head)
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<" NULL ";
}

void insertAtHead(node* &head , int val)
{
	node*n =new node (val);
	n->next=head;
	head=n;
}

void deletion(node* &head , int val)
{
	node* temp=head;
	while(temp->next->data!=val)
	{
		temp=temp->next;
	}
}

void deleteAtHead(node* & head)
{
	node* todelete=head;
	head=head->next;
	
	delete todelete;
}

bool search(node* head , int key)
{
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

int main()
{
	node* head=NULL;
	int choice=0;

	do{

	cout<<"\n  1.Insert At Tail \n ";
	cout<<" 2.Insert At Head \n ";
	cout<<" 3.Display List \n ";
	cout<<" 4.Deletion \n ";
	cout<<" 5.Delete At Head \n ";
	cout<<" 6.Search in List \n ";
	cout<<" 7.Exit program \n ";
	cout<<" Enter the choice \n ";
	cin>>choice;
		
		switch (choice)
		{
			case 1: 
				insertAtTail(head,1);	
			break;
			case 2: 
				insertAtHead(head,4);
			break;
			case 3:
				display(head);
			break;
			case 4:
				deletion(head,4);
			break;
			case 5:
			 	deleteAtHead(head);
			break;
			case 6:
				cout<<search(head,5);
			break;
	 		case 7:
				exit(0);
			break;
			default: cout<<"Invalid choice"<<endl;
		}
	}
	while(choice!=7);	
	
	return 0;
	
	
	
}