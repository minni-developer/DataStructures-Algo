#include <iostream>
using namespace std;
class queue
{
private :
	int front;
	int rare;
	int size;
	int *Q;

public:	
	queue()
	{
		front=rare=-1;
		size=10;
		Q=new int [size];
	}
	queue(int size)
	{
	front=rare=-1;
	this->size=size;
	Q=new int [this->size];
	}
void enque(int x)
{
	if (rare==size-1)
	{
		cout<<"Queue is full \n";
	}
	else 
	{
		rare++;
		Q[rare]=x;
	}
}

int deque()
{
	int x;
	if (front==rare)
	{
	cout<<"Queue is empty \n";		
	}
	else 
	{
	x=Q[front+1];
	front++;	
	}
	return x;
}

void display()
{
	for(int i=front+1;i<=rare;i++)
	{
		cout<<Q[i];
	}
}
};


int main()
{
	queue q(5);
	q.enque(1);
	q.enque(2);
	q.enque(3);
	q.display();
	
}
