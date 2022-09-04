// unbounded search : when we don't know the size (infinite sized array) of a sorted array but we have to search for an element.


#include <iostream>

using namespace std; 

// solution 1 : traverse from beginning and stops when you find element or an element greater than key.
// time comp : O(positon of element)


int binarySearch(int arr[], int x, int l, int r)
{
    int mid;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid] > x)
            r = mid-1;
        else
            l = mid + 1;
    }

    return -1;
}


// binary search based
// time comp: O(log(position of element))
int unboundedSearch(int arr[], int x)
{
    if(arr[0] == x)
        return 0;
    int i = 1;
    while(arr[i]<x)
        i = i*2;
    if(arr[i] == x)
        return i;
    return binarySearch(arr, x, i/2+1, i-1);
}


int main()
{
    // int n ;
    // cin>>n;
    // int arr[n];
    // infinite array
    int arr[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
    int x;
    cin>>x;
    cout<<unboundedSearch(arr,x);
    return 0;
}