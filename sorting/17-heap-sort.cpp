#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// heap sort works in 3 steps.
// step 1 : we build a max heap for sorting in ascending order. (for reverse sorting use min heap)
// step 2: we swap last element with root of heap 
// step 3: heapify again


// build a max heap
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i + 2;
    
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(arr, n, largest);
    }

}

void buildHeap(int arr[], int n)
{
    for (int i=(n-2)/2; i>=0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);
        // size of heap reduces by 1 in each iteration.
        maxHeapify(arr, i, 0);
    }
}



int main()
{
    int arr[] {1,4,2,3,4,7,8,9,6,10,11,15,14,12,16,13,20,25,14,21,23,22,30,29,27,28,26,25};
    // int arr[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    // int arr[] {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array: "<<endl;
    printArray(arr,n);
    
    heapSort(arr,n);
    
    cout<<"Sorted array: "<<endl;
    printArray(arr,n);
    return 0;
}