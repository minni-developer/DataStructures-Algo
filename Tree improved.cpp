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
			Root = NULL;
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
void Idisplay()
{
	cout<<"Inorder Traversal";
	this->InOrder(Root);
	/*cout<<endl<<"Prorder Traversal";
	this->PreOrder(Root);
	cout<<endl<<"Postorder Traversal";
	this->PostOrder(Root);*/
}
void Predisplay()
{
	
	cout<<endl<<"Prorder Traversal";
	this->PreOrder(Root);

}

void Postdisplay()
{
	cout<<endl<<"Postorder Traversal";
	this->PostOrder(Root);
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
	int select = 0;
	int val = 0;
	
     do
		{
			cout << "  Enter 1 for insertion  " << endl;
	cout << "  Enter 2 for Inorder traversal " << endl;
	cout << "  Enter 3 for Preorder traversal  " << endl;
	cout << "  Enter 4 for Postorder traversal " << endl;
	cout << "  Enter 5 to display maximum element " << endl;
	cout << "  Enter 6 to dsiplay minimum element   " << endl;
	cout << "  Enter 7 for deletion  "  << endl;
    cout << "  |||  Enter 0 to stop ||| "  << endl;
			cin >> select;

			switch ( select )
		{
			case 1:
			// INSERTION 
    cout << " Enter value that u want to insert " << endl;
	cin >> val;
	T.insertTree(val);

	break;

		case 2:
			// INORDER TRAVERSAL
			T.Idisplay();
	break;

		case 3:
			// PREORDER TRAVERSAL
			T.Predisplay();
			break;

		case 4:
			// POSTORDER TRAVERSAL
			T.Postdisplay();
			break;


		case 5:
			// MAXIMUM ELEMENT
			T.max();
			break;

		case 6:
			// MINIMUM ELEMENT

			T.min();
			break;

		case 7:
			// DELETION
			cout << " Enter the  node which u wanna delete " << endl;
			cin >> val;
			T.DNode(val);
			break;
			}
		} while ( select != 0 );

		cout << " |||| PROGRAM ENDED |||| " << endl;

  return 0;

	}