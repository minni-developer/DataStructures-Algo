#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    int *a = nullptr;
    int length = 0;
    int min = 0;
    int max = 0;
    int minIndex = 0;
    int maxIndex = 0;

    cout << "Enter the size of the array: ";
    cin >> size;

    a = new int[size];

    cout << "Enter the number of values to store: ";
    cin >> length;

    cout << "Enter the values: ";
    for (int i = 0; i < length; i++)
    {
        cin >> a[i];
    }

    min = a[0];
    max = a[0];

    for (int i = 0; i < length; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            minIndex = i;
        }

        if (a[i] > max)
        {
            max = a[i];
            maxIndex = i;
        }
    }

    cout << "The minimum value in the array is " << min <<  endl;
    cout << "The maximum value in the array is " << max << endl;

    delete[] a; // Don't forget to free the allocated memory.

    return 0;
}
