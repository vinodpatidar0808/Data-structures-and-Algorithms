// given a sorted rotated array (rotated unknown number of times). Find an element.

#include <iostream>

using namespace std; 

// linear search :O(n)

// binary search based
// when array is sorted and rotated one half of array is still guaranteed to be sorted

int search(int arr[], int n, int x)
{
    int l {0}, r {n-1};
    int mid ;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] == x)
            return mid;
        
        if(arr[l] <= arr[mid])
        {
            if(x>=arr[l] && x<arr[mid])
                r = mid-1;
            else 
                l = mid+1;
        }
        else
        {
            if(x>arr[mid] && x<=arr[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n ;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
        cin>>arr[i++];
    
    int x;
    cout<<"Enter element to search"<<endl;
    cin>>x;
    int res = search(arr, n, x);
    if(res != -1)
        cout<<x<<" is present at index "<<res<<endl;
    else
        cout<<x<<" is not present in the array."<<endl;
    
    return 0;
}