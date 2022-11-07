// heap sort time comp : O(nlog(n)) : in all cases

/**
 * we will build heap sort in 2 steps 
 * step 1: build heap from given array (to sort in ascending order we will use max heap and for descending order we will use min heap)
 * step 2: repeatedly swap root node with last node and reduce size of heap size and then heapify
 */


#include <iostream>
#include <utility>

using namespace std; 

void heapSort(int [], int );
void buildHeap(int [], int );
void heapify(int [], int , int); 


// time comp : O(nlog(n))
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for(int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// time comp: O(n)
void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2; i>=0; i--)
        heapify(arr, n, i);
}

// time comp : O(log(n))
void heapify(int arr[], int n, int ind)
{
    int l = (2*ind+1);
    int r = (2*ind+2);
    int largest = ind;

    if(l<n && arr[l]>arr[ind])
        largest = l;
    if(r < n &&  arr[r]>arr[largest])
        largest = r;
    
    if(largest != ind)
    {
        swap(arr[ind], arr[largest]);
        heapify(arr, n, largest);
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
    int arr[] {10,8,7,6,4,1,2,5,11,16,18,20,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    heapSort(arr,n);
    printArray(arr, n);
    return 0;
}