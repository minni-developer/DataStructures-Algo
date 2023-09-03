#include <iostream>
using namespace std;

void insertSpecific(int arr[],int &n)
{	
	if (n==10)
	{
		cout<<"Max limit of Array Reached \n";
		return;
	}
	int key,num;
   cout<<" enter key to add element \n";
    cin>>key;
     key--;
     if (key>10)
     {
     	cout<<"***Invalid Key***";
     	return;
	 }
     cout<<" enter a number \n";
     cin >>num;
     for(int i=n;i>=key;i--)
     {
         arr[i+1]=arr[i];
     }
     arr[key]=num;
    n++;    	
}
void insertLast(int arr[],int &n)
{
	if (n==10)
	{
		cout<<"Max limit of Array Reached \n";
		return;
	}
	int item;
	cout<<"enter item to insert : ";
	cin>>item;
	arr[n]=item;
	n++;
}
void deleteSpecific(int arr[],int &n)
{
	if (n==-1)
	{
		cout<<"Min limit of Array Reached \n";
		return;
	}
	int key;
	cout<<" enter key to delete element \n";
    cin>>key;
     key--;
      
     for(int i=key;i<=n;i++)
     {
         arr[i]=arr[i+1];
     }
     n--;
}
void deleteLast(int arr[],int &n)
{
	if (n==-1)
	{
		cout<<"Min limit of Array Reached \n";
		return;
	}
	n--;
}

int main()
{   
    int n=8,key,x;
    int arr[10];
      

  cout<<" enter 8 elements in array \n";
  for(int i=0;i<8;i++)
  {
    cin>>arr[i];  
  } 
    
	do {    
 cout<<" \n enter a choise \n";
 cout<<" 1.Insert at a specific index\n";
 cout<<" 2.Insert at last \n";
 cout<<" 3.Delete at a specific index \n";  
 cout<<" 4.Delete at last\n"; 
 cout<<" 5.Display at size\n"; 
 cout<<" 6.exit program \n";
 cin>>x;

     
 switch ( x)
 {
    case 1 : 
   		insertSpecific(arr,n);
     break;
     
    case 2 : 
   		insertLast(arr,n);
     break;
     
    case 3 : 
   		deleteSpecific(arr,n);
     break;
    
    case 4 : 
  		 deleteLast(arr,n);
     break;
     
    case 5 : 
     cout<<"Size of Array : "<<n<<"\n";
     cout<<"New Array \n";
     for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }
     break;
    case 6 : 
       exit(0);
  	break;
 	default: 
 		system("cls");	
		 cout<<"***Error Occured Try Again***"<<endl;
 }//end of switch
        
   }//end of DO 
 
 while (true);
 
    return 0;
}