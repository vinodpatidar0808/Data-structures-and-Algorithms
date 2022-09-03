// in ternary search we divide the array in 3 equal parts and then look for the element
// array must be sorted for binary/ternary search to work

#include <iostream>

using namespace std; 

int ternarySearchRec(int arr[], int x, int l, int r)
{
    if(l>r)
        return -1;

    int mid1 = l + (r-l)/3 ;
    int mid2 = r - (r-l)/3 ;

    if(arr[mid1]==x)
        return mid1;
    else if(arr[mid2] == x)
        return mid2;
    else if(x<arr[mid1])
        return ternarySearchRec(arr,x,l,mid1-1);
    else if(x<arr[mid2])
        return ternarySearchRec(arr, x, mid1+1, mid2-1);
    else 
        return ternarySearchRec(arr, x, mid2+1, r);
}

int ternarySearch(int arr[], int n, int x)
{
    int l {0}, r {n-1};
    int mid1, mid2;
    while(l<=r)
    {
        mid1 = l + (r-l)/3;
        mid2 = r - (r-l)/3;
        if(arr[mid1]==x)
            return mid1;
        else if(arr[mid2] == x)
            return mid2;
        else if(x<arr[mid1])
            r = mid1-1;
        else if(x < arr[mid2])
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
        else 
            l = mid2 + 1;
    }
    return -1;
}



int main()
{
    int arr[20] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int x;
    cout<<"Enter value to search"<<endl;
    cin>>x;

    // int res = ternarySearchRec(arr, x, 0, 19);
    int res = ternarySearch(arr, 20, x);
    if(res != -1)
        cout<<x<<" is located at index "<<res<<endl;
    else
        cout<<x<<" is not present in the array."<<endl;

    return 0;
}