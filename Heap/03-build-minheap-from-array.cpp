// remember heap is always a complete binary tree

#include <iostream>

using namespace std; 

void heapify(int arr[], int size, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if(l < size &&  arr[l]<arr[i])
        smallest = l;
    if(r< size && arr[r]< arr[smallest])
        smallest = r;
    
    if(smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, size, smallest);
    }
}

/**
 * last element size-1 
 * parent of element at index i = floor((i-1)/2)
 * parent of last element is at index = floor((size-2)/2)
 * */

// time comp : O(n)
void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2; i>=0;i--)
    {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] {5,6,2,4,3,1,10,11,12,8,7,9,15,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    buildHeap(arr, n);
    printArray(arr, n);
    return 0;
}