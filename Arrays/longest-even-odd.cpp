// find the length of the longest subarray which has alternating even and odd numbers.
#include <iostream>

using namespace std;

int longestEvenOdd(int arr[],int n)
{
    int len = 1;
    int currLen = 1;
    for(int i=1 ;i<n;i++)
    {
        int last = arr[i-1]%2;
        if(arr[i]%2 != last)
        {
            currLen++;
        }
        else
            currLen = 1;
        len = max(currLen, len);
    }
    return len;
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
    
    cout<<longestEvenOdd(arr,n);
    return 0;
}