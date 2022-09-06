#include <iostream>

using namespace std; 


void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

void insertionSort(int arr[], int n)
{
    int j, currVal;
    for(int i=1;i<n;i++)
    {   
        currVal = arr[i];
        j= i-1;
        while(j>=0 && arr[j] > currVal)
        // for reverse sorting
        // while(j>=0 && arr[j] < currVal)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currVal;
    }
}

int main()
{
        int arr[] {4,5,3,1,2,0,10,11,15,12,10,1,2,9,20,25,24,22,23,2,3};
    // int arr[] {1,2,3,4,5,6,7,8,9,10};
    // int arr[] {10,9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: "<<endl;
    printArray(arr,n);

    insertionSort(arr, n);
    // selectionSortReverse(arr,n);

    cout<<"Sorted array:"<<endl;
    printArray(arr,n);
    return 0;
}