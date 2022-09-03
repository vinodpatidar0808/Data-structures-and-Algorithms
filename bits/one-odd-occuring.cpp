// given an array of intergers where all numbers occur even no of times and one no. which occurs odd number of time find this number.

#include <iostream>

using namespace std;

// time comp : O(n^2)
int oddOccuring(int arr[], int n)
{
    int count {0};
    for(int i=0;i<n;i++)
    {
        count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==arr[i])
                count++;
        }
        if(count%2 != 0)
            return arr[i];
    }
    return 0;
}


/*
    x^y = y^x;
    x^0 = x
    x^x = 0
*/

// time comp: O(n)
int oddOccuringXor(int arr[], int n)
{
    int xValue = 0;
    for(int i=0;i<n;i++)
        xValue ^= arr[i];
    return xValue;
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
    cout<<"size of array: "<<endl;
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

    cout<<"Odd occuring "<<oddOccuring(arr,n)<<endl;
    cout<<"Odd occuring "<<oddOccuringXor(arr,n)<<endl;
    return 0;
}