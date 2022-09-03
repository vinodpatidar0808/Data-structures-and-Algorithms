// given a sorted array and an element x find the index of last occurrence of x

#include <iostream>

using namespace std; 

// time comp: O(n)
int lastOccurrence(int arr[], int n, int x)
{
    for(int i=n-1;i>=0;i--)
        if(arr[i] == x)
            return i;
        
    return -1;
}

// using binary search 
// time comp : O(log(n))

int lastOccurrenceBinary(int arr [], int n, int x)
{
    int l {0}, r {n-1};
    int res = -1;
    int mid ;
    while(l<=r)
    {
        mid = l + (r-l)/2;

        if(x<arr[mid])
            r = mid-1;
        else if(x>arr[mid])
            l =mid+1;
        else if( mid ==n-1 || arr[mid+1]!=x)
            return mid;
        else 
            l = mid+1;
    }
    return -1;
}

int main()
{
    int arr[] {1,2,2,2,2,3,4,5,5,5,5,5,6,6,6,7,7,8,8,8};
    cout<<"Enter element to get it's last index "<<endl;
    int x;
    cin>>x;
    int n = sizeof(arr)/sizeof(arr[0]);
    // int res = lastOccurrence(arr, n, x);
    int res = lastOccurrenceBinary(arr, n, x);
    if(res != -1)
        cout<<"Last index of "<<x<<" is "<< res<<endl;
    else  
        cout<<"Element does not exist in array"<<endl;

    return 0;
}