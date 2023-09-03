#include <iostream>
using namespace std;
int main()
{

	int arr[5]={7,8,1,5,2};
	int n=5;
	int loc=1;
	int item;
	cout<<"enter element to search ";
	cin>>item;
	for (int i=1;i<=n;i++)
	{
		if (arr[i]==item)
		{
			cout<<"found at "<<i<<endl;
			break;
			}
		
		loc++;	
	}
	if (loc>=n )
	{
		cout<<" not found "<<endl;
	}
	
	for (int i=1;i<=n;i++)
	{
		cout<<i<<". "<<arr[i]<<endl;
	}
}
