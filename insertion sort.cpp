#include<iostream>
using namespace std;
void sorting (int* arr,int tot){
	int index;
	   for(int i=1; i<tot; i++)
    {
        int elem = arr[i];
        if(elem<arr[i-1])
        {
            for(int j=0; j<=i; j++)
            {
                if(elem<arr[j])
                {
                     index = j;
                    for(int k=i; k>j; k--)
                        arr[k] = arr[k-1];
                    break;
                }
            }
        }
        else
            continue;
        arr[index] = elem;
    }
    cout<<"\nThe New Array (Sorted Array):\n";
    for(int i=0; i<tot; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
	
}
int main()
{
    int arr[50], tot;
    cout<<"Enter the Size for Array: ";
    cin>>tot;
    cout<<"Enter "<<tot<<" Array Elements: ";
    for(int i=0; i<tot; i++)
        cin>>arr[i];
        sorting(arr,tot);
 
    return 0;
}
