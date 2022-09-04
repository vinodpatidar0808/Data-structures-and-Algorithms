// peak element : Element which is not smaller (arr[peak - 1] <= arr[peak] <= arr[peak+1] ) than both of it's neighbours 

// array is unsorted


#include <iostream>

using namespace std; 

// O(n) : solution 
// return index of peak element 
int peakElement(int arr[], int n)
{
    if(n == 1)
        return 0;
    if(arr[0] >= arr[1])
        return 0;
    if(arr[n-1]>=arr[n-2])
        return n-1;

    for(int i = 1; i<n-1;i++)
    {
        if(arr[i]>= arr[i-1] && arr[i]>=arr[i+1])
            return i ;
    }
    // to avoid return warnings
    return -1;
}


// binary search based
// an independent array will always have a peak element.
//check middle element if mid-1 >= mid then you will find atleast one peak in left side, if mid+1>= mid then you will find atleast 1 peak in right side.
int peak(int arr[], int n)
{
    int l  {0};
    int r {n-1};
    int mid ;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if((mid==0 || arr[mid] >= arr[mid-1]) &&(mid==n-1 || arr[mid]>=arr[mid+1]))
            return mid;
        if(mid>0 && arr[mid-1]>=arr[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main()
{
    int n ; 
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
        cin>>arr[i++];

    cout<<"Peak element is located at index "<<peakElement(arr, n)<<endl;
    cout<<"Peak element is located at index "<<peak(arr, n)<<endl;

    return 0;
}