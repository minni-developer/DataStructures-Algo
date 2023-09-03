#include <iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,3,4,5};
	int n=5;
	int item;
	
	// LB = lower bound &&  UB = Upper bound
	cout<<"enter element to search ";
	cin>>item;
	int LB =0;
	int UB =n;
	int  MID =(UB+LB)/2;
    while ( LB<=UB && arr[MID]!=item)
	{
		if  (item<arr[MID])
		{
			UB=MID-1;
		}
		else 
		{
			LB=MID+1;	
		}
		 MID =(UB+LB)/2;
	}
	if  ( arr[MID]!=item)
	{
		cout<<"not found ";
	}
	else 
	cout<<" found";
}
