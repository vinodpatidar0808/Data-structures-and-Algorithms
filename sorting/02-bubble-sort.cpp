// time complexity of bubble sort is O(n^2)

#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

void bubbleSort(int arr[], int n)
{

    // in each iteration we shift larger values in the end.
    /*
    for(int i=0;i<n-1;i++)
    {
        // for optimizing 
        bool flag = false;
        for(int j=0; j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            // for reverse sorting
            if(arr[j] < arr[j+1])

            {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }    
    */

    for(int i=0;i<n-1;i++)
    {
        bool flag = false;
        for(int j=n-1;j>0;j--)
        {
            if(arr[j] < arr[j-1])
            // for reverse sorting
            // if( arr[j] > arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }

}

int main()
{
    // int arr[] {4,5,3,1,2,0,10,11,15,12,10,1,2,9,20,25,24,22,23,2,3};
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    // int arr[] {10,9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: "<<endl;
    printArray(arr,n);
    bubbleSort(arr, n);
    cout<<"Sorted array:"<<endl;
    printArray(arr,n);
    return 0;
}