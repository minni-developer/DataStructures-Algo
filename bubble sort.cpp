 #include<iostream>
using namespace std;
void Bubble(int* arr,int n){
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
            	int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"\nArray Sorted Successfully!\n";
    cout<<"\nThe New Array is: \n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n, i, arr[50], j, temp;
    cout<<"Enter the Size ";
    cin>>n;
    cout<<"Enter "<<n<<" Numbers: ";
    	    for(i=0; i<n; i++)
        cin>>arr[i];
        Bubble(arr,n);
    return 0;
}
