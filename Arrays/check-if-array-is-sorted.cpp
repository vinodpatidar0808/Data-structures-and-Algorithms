// check if array is sorted in ascending order

#include <iostream>

using namespace std; 

bool checkSorted(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}

int main()
{
    int n ;
    cin>>n;
    int  arr[n];
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    bool isSorted = checkSorted(arr, n);
    cout<<(isSorted?"array is sorted":"array is not sorted");

    return 0;
}