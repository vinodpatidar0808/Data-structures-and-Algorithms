// For binary search array must be sorted
// time complexity of binary search is O(log(n))


#include <iostream>

using namespace std; 

int binarySearchRec(int arr[], int x, int l, int r)
{
    if(l>r)
        return -1;
    int mid = l + (r-l)/2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid] > x)
        return binarySearchRec(arr, x, l, mid-1);
    else 
        return binarySearchRec(arr, x, mid+1, r);
}


int binarySearch(int arr[], int n, int x)
{
    int l {0}, r {n-1};
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

int main()
{
    int arr[10] {1,2,3,4,5,6,7,8,9,10};
    int x;
    cin>>x;
    // int res = binarySearchRec(arr, x, 0, 9);
    int res = binarySearch(arr, 10, x);
    if(res != -1)
        cout<<x<<" is located at index "<<res<<endl;
    else
        cout<<x<<" is not present in the array."<<endl;
    return 0;
}