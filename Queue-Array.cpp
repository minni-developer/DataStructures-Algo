#include<iostream>
using namespace std;
int arr[5];
int front= -1, rear=-1;
 int size= 5;
 int value;
 
 bool isfull()
 {
 	if (rear == size-1)
 	{
 		return true;
	}
	else
	{
		return false;
	}
}
bool isempty()
{
	if((front == -1) || (front > rear))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
void enque()
{
	if (isfull())
	{
		cout<<"queue is full"<<endl;
	}
	else 
	front =0;
	cout<<"enter value : ";
    for (int i=0; i<1; i++)
	{
		cin>> value;
		rear++;
		arr[rear]=value;
	}}
	int deque()
	{
		if (isempty())
		{
			cout<<"queue underflow" <<endl;
			return -1;
		}
		if ( front>= rear)
		{
			front= -1;
			rear = -1;
		}
		else 
		front++;
	}
	void display()
	{
		if( front== -1)
		cout<<"Queue is empty" <<endl;
		else
		{
			cout<<"Queue elements are: ";
			for( int i = front; i<= rear; i++)
			cout<<arr[i]<<" "<<endl;
		}
	}
	int main()
	{ int ch;
	cout<<"1. Insert element to queue"<<endl;
	cout<<"2. Delete element from queue"<<endl;
	cout<<"3. Display all elements of queue"<<endl;
	cout<<"4. Exit"<<endl; 
	do{
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch (ch)
		{
			case 1: enque();
			break;
			case 2: deque();
			break;
			case 3:
				{
					display();
				}
			break;
			case 4: cout<< "Exit"<<endl;
			break;
			default: cout<<"Invalid choice"<<endl;
		}
	}
	while(ch!=4);
	return 0;
	}
