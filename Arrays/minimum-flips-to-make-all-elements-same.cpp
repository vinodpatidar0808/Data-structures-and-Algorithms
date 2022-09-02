// given a binary array, make all elements of array same either by flipping 0's or 1's, you can flip consecutive 1s or 0s in one go.
// print indices of flipping: eg. from index i to index j 

#include <iostream>

using namespace std;

// you are allowed to flip consecutive 1's or 0's in one go. count groups of both 1s and 0s and whichever count is less flip them.

// time comp: O(n), but requires 2 traversals
void countFlips(int arr[], int n)
{
    int zeroGroup {0};
    int oneGroup {0};
    int i = 0;
    while(i<n)
    {
        int j = i+1;
        while(j<n && arr[i] == arr[j])
            j++;
        if(arr[i]==1)
            oneGroup++;
        else
            zeroGroup++;
        i = j;
    }
    // return zeroGroup<oneGroup?zeroGroup:oneGroup;
    int flipElement = zeroGroup<=oneGroup?0:1;

    int start {0};
    for(int i=0;i<n;i++)
    {
        start = i;
        while(i<n && arr[i]==flipElement)
        {
            i++;
        }
        if(arr[start]==flipElement)
        {
            cout<<"flip from index "<<start<<" to index "<<i-1<<endl;
        }
    }
}


void countFlipsFast(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            if(arr[i]!=arr[0])
                cout<<"from index "<<i<<" to ";
            else
                cout<<i-1<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
        cout<<n-1<<endl;
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
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
    cout<<"original array: "<<endl;
    printArray(arr, n);

    // countFlips(arr,n);
    countFlipsFast(arr, n);
    return 0;
}