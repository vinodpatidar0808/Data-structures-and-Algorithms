// time complexity : O(n^2)

#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}


void selectionSort(int arr[], int n)
{
    int i, j, minIdx;
    for(int i=0;i<n-1;i++)
    {
        minIdx = i;
        for(int j=i+1;j<n;j++)
            if(arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i],arr[minIdx]);
    }
}

// for reverse sorting
void selectionSortReverse(int arr[], int n)
{
    int i, j, maxIdx ;
    for(int i=0;i<n;i++)
    {
        maxIdx = i;
        for(int j=n-1;j>i;j--)
            if(arr[j] > arr[maxIdx])
                maxIdx = j;

        swap(arr[i],arr[maxIdx]);
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

    selectionSort(arr, n);
    // selectionSortReverse(arr,n);

    cout<<"Sorted array:"<<endl;
    printArray(arr,n);
    return 0;
}