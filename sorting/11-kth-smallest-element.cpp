// given an unsorted array of distinct numbers find kth smallest element in it.

#include <iostream>
#include <algorithm>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// both the methods modifies actual array.

int kthSmallest(int arr[], int n, int k)
{

    if(k>n)
        return -1;
    sort(arr, arr+n);
    return arr[k-1];
}


// using quickselect algorithm
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for(int j = l;j<=r;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i++],arr[j]);
        }
    }
    swap(arr[i],arr[r]);
    return i;
}

int kSmallest(int arr[], int n, int k)
{
    int l {0}, r {n-1};
    while(l<=r)
    {
        int p = partition(arr, l, r);
        if(p==k-1)
            return p;
        else if(p>k-1)
            r = p-1;
        else 
            l = p+1;
    }
    return -1;
}

int main()
{
    // int arr[] {1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[] {10,9,8,7,6,5,4,3,2,1};
    int arr[] {11,8,2,15,16,7,10,21,14,16,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k {4};
    cout<<"Original array: "<<endl;
    printArray(arr, n);
    // int res = kthSmallest(arr, n, k);
    int res = kSmallest(arr, n, k);
    cout<<k<<"th smallest element in array is: "<<arr[res]<<endl;
    cout<<endl;
        
    return 0;
}