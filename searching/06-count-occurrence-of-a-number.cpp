// Given a sorted array and a number x, count the occurrences of x in array.

#include <iostream>

using namespace std; 

// time comp: O(n)
int countOccurrence(int arr[], int n, int x)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x)
            count++;
    }
    return count;
}


int firstIndex(int arr [], int n, int x)
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
        else if( mid ==0 || arr[mid-1]!=x)
            return mid;
        else 
            r = mid-1;
    }
    return -1;
}

int lastIndex(int arr [], int n, int x)
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


// to count number of elements we need it's first index and last index. Count = lastIndex - firstIndex + 1
// time comp : O(log(n))
int countOccurrenceBinary(int arr[], int n, int x)
{
    int firstInd = firstIndex(arr,n,x);
    if(firstInd==-1)
        return 0;
    int lastInd = lastIndex(arr, n, x);
    return (lastInd - firstInd + 1);
}

int main()
{
    int arr[] {1,2,2,2,3,4,4,4,4,5,5,6,9,9,9,9,11,11,11,12,12,13,14,15,16,17,18,18,18,19,20,20,21};
    cout<<"Enter element to get it's count "<<endl;
    int x;
    cin>>x;
    int n = sizeof(arr)/sizeof(arr[0]);
    // int res = countOccurrence(arr, n, x);
    int res = countOccurrenceBinary(arr, n, x);
    if(res != 0)
        cout<<x<<" appears "<<res<<" times in the array."<<endl;
    else  
        cout<<"Element does not exist in array"<<endl;

    return 0;
}