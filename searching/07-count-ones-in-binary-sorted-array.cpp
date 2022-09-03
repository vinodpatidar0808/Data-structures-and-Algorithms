// Given a sorted binary array find number of times 1 appears in the array.

#include <iostream>

using namespace std; 

// time comp: O(n)
int countOnes(int arr[], int n)
{
    int count = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] == 0)
            break;
        count++;
    }
    return count;
}


int countOnesBinary(int arr [], int n)
{
    int l {0}, r {n-1};
    int res = -1;
    int mid ;
    while(l<=r)
    {
        mid = l + (r-l)/2;

        if(1<arr[mid])
            r = mid-1;
        else if(1>arr[mid])
            l =mid+1;
        else if( mid ==0 || arr[mid-1]!=1)
        {
            res = mid;
            break;
        } 
        else 
            r = mid-1;
    }
    
    return (res == -1) ? 0 : (n - res );
    
}



int main()
{
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int arr[n] ;
    int i =0;
    while(i<n)
        cin>>arr[i++];
    cout<<endl;
    // int res = countOnes(arr, n);
    int res = countOnesBinary(arr, n);
    if(res != 0)
        cout<<"1 appears "<<res<<" times in the array."<<endl;
    else  
        cout<<"1 does not exist in array"<<endl;

    return 0;
}