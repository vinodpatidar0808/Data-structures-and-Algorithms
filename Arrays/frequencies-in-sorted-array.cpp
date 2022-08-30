// print frequency of all different elements in a sorted array.
// if array is not sorted: 1) use 2 loops O(n^2).   2) with maps O(n) time, O(n) space

#include <iostream>

using namespace std;



void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}


void printFrequencies(int arr[], int n)
{
    int freq=1;
    int i=1;
    while(i<n)
    {
        while(i<n && arr[i]==arr[i-1])
        {
            freq++;
            i++;
        }

        cout<<arr[i-1]<<" -> "<<freq<<endl;
        i++;
        freq=1;
    }

    if(n==1 || arr[n-1]!=arr[n-2])
        cout<<arr[n-1]<<" -> "<<1<<endl;
}


void frequencies(int arr[], int n)
{

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

    // printFrequencies(arr,n);
    frequencies(arr, n);
    return 0;
}