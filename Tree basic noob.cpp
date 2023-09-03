#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* LChild;
		Node* RChild;	
	Node(int data)
	{
		this->data = data;
		this->LChild = NULL;
		this->RChild = NULL;
		
	}
};

//////////////////////////////
class Tree{
	
	public:
	Node* Root;
	

	
	Tree()
	{
		Root = NULL;
	}

///////////////////////////////
void insertTree(int data)
{

	Node* current;
	Node* parent;	
	Node* NewNode = new Node(data);	
	
	if(Root == NULL)
		Root = NewNode;
	else
	{
	
		current = Root;
		while(current != NULL)
		{
			parent = current;
			if(data<current->data)
			{
				current = current->LChild;
				if(current == NULL)
					parent->LChild = NewNode;				
			}
			else
			{
				current = current->RChild;
				if(current == NULL)
					parent->RChild = NewNode;
			}
		}		
	}	
	
}
/////////////////////////////////
void max()
{
	Node* current;
	current = Root;
	while(current->RChild!= NULL)
		current = current->RChild;
		
	cout<<"Max Node value is..."<<current->data<<endl;
}
/////////////////////////////////
void min()
{
	Node* current;
	current = Root;
	while(current->LChild!= NULL)
		current = current->LChild;
		
	cout<<"Minimum Node value is..."<<current->data<<endl;
}
/////////////////////////////////
Node* getsuccessor(Node* delnode)
{
	Node* Sparent = delnode;
	Node* successor = delnode;
	Node* current = delnode->RChild;
	
	while(current != NULL)
	{
		Sparent = successor;
		successor = current;
		current = current->LChild;
	}
	
	if(successor != delnode->RChild)
	{
		Sparent->LChild = successor->RChild;
		successor->RChild = delnode->RChild; 
	}
	
	return successor;
}
/////////////////////////////////
void DNode(int key)
{
	Node* parent;
	Node* current;
	Node* successor;
	current = Root;
	bool IsLChild = true;
	//Finding the Node to be deleted
	while((current->data != key ))//&& (current != NULL))
	{
		parent = current;
		if(key<current->data)
		{
			IsLChild = true;
			current = current->LChild;	
		}
		else
		{
			IsLChild = false;
			current = current->RChild;
		}
		if(current == NULL)
			cout<<endl<<"not found";
	}//End of Finding
	//If deleting Node have no child
	if((current->LChild == NULL)&& (current->RChild == NULL))
	{
		if(current == Root)
			Root == NULL;
		else if(IsLChild == true)
			parent->LChild = NULL;
		else 
			parent->RChild = NULL;	
	}
	//If deleting node one child (Lft Child)
	else if(current->RChild == NULL)
	{
		if(current == Root)
			Root = current->LChild;
		else if(IsLChild == true)
			parent->LChild = current->LChild;
		else
			parent->RChild = current->LChild;
	}
	//If deleting node one child (Right Child)
	else if(current->LChild == NULL)
	{
		if(current == Root)
			Root = current->RChild;
		else if(IsLChild == true)
			parent->LChild = current->RChild;
		else
			parent->RChild = current->RChild;
	}
	//If deleting node two children
	else
	{
		successor = getsuccessor(current);
		if (current == Root)
			Root = successor;
		else if (IsLChild == true)
			parent->LChild = successor;
		else
			parent->RChild = successor;
			
		successor->LChild = current->LChild;
	}
}

/////////////////////////////////
void display()
{
	cout<<"Inorder Traversal";
	this->InOrder(Root);
	/*cout<<endl<<"Prorder Traversal";
	this->PreOrder(Root);
	cout<<endl<<"Postorder Traversal";
	this->PostOrder(Root);*/
}
/////////////////////////////////
	void InOrder(Node* T)
	{
		Node* Current;
		Current = T;
		
		if(T != NULL)
		{
			InOrder(Current->LChild);
			cout<<" "<<Current->data;
			InOrder(Current->RChild);
		}
	}
/////////////////////////////////
void PreOrder(Node* T)
{
		Node* Current;
		Current = T;
		
		if(T != NULL)
		{
			
			cout<<" "<<Current->data;
			PreOrder(Current->LChild);
			PreOrder(Current->RChild);
		}
}	
	/////////////////////////////////
void PostOrder(Node* T)
{
		Node* Current;
		Current = T;
		
		if(T != NULL)
		{
			PostOrder(Current->LChild);
			PostOrder(Current->RChild);
			cout<<" "<<Current->data;
		}
}
	
};
//////////////////////////////////////////////

int main(void)
{
	Tree T;
	int option;
	
//	T.insertTree(45);
//	T.insertTree(5);
//	T.insertTree(6);
//	T.insertTree(4);
//	T.insertTree(145);
//	T.insertTree(475);
//	T.insertTree(50);
//	T.insertTree(48);
//	T.insertTree(46);
//	T.insertTree(200);
//	T.insertTree(500);
//	T.display();
//	//T.max();
//	//T.min();
//	cout<<endl;
//	T.DNode(45);
//	T.display();
//	
	//cout<<""
//	List.InsertFirst(45);
//	List.InsertFirst(405);
//	List.InsertFirst(5);
//	List.InsertLast(999);
//	List.FTraversing();
		int pos=0;
		int choice = 0;
		int val=0;
		do
		{
		
	cout << "\n  1. Insertion of Node " << endl;
	cout << "  2. Find Minimum " << endl;
	cout << "  3. Find Maximum " << endl;		
	cout << "  4. Deletion of Node" <<endl;
	cout << "  5. Inorder Tree  " << endl;
	cout << "  6. Preorder Tree " << endl;
	cout << "  7. Postorder Tree  " << endl;
	cout << "  8. Display Tree " << endl;
	cout << "  9. **Exit Program** " << endl;
		cin >> choice;

	switch ( choice )
		{
	case 1:
			// INSERTION
    cout << " Enter element to insert " << endl;
	cin >> val;
	T.insertTree(val);
			break;
			
	case 2:
			//MIN
	T.min();
			break;
	
	case 3:
			// MAX
	T.max();
			break;
	break;

	case 4:
			// DELETION 
   cout << " Enter position to delete " << endl;
	cin >> pos;
  	T.DNode(pos);
			break;
	break;

	case 5:
			// INORDER
	T.InOrder();
			break;
	break;
	
	case 6:
			// PREORDER
	T.PreOrder(Node *T);
			break;

	case 7:
			// POSTORDER
	T.PostOrder(Node *T);
			break;

	
	case 8:
			//  DISPLAY
	T.display();
			break;


	case 9:
			//  EXIT
		exit(0);
			break;

		}
	}
	while(choice<=9);
	
	return 0;
}
