#include <iostream>
using namespace std;
int main ( )
{
	int arr [5]={12,3,6,0,-3};
	int in,out,n=5;
	for(out=0;out<n-1;out++)
	{
		int min=out;
		in=out+1;
		while(in<n)
	{
		if(arr[in]<arr[min])
		{
			min=in;
		}
			in++;
	}
	int temp;
	temp=arr[out];
	arr[out]=arr[min];
	arr[min]=temp;
	}
	for(out=0;out<n;out++)
	{
		cout<<arr[out]<<" ";
		
	}
}
