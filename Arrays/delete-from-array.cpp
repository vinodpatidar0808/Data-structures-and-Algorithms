// delete a given element from the array if it exist

#include <iostream>

using namespace std; 

int deleteFromArray(int arr[], int n, int x)
{
    int i ;
    for(i = 0; i<n;i++)
    {
        if(arr[i] == x)
            break;
    }
    if(i==n)
        return n;
    for(int j=i;j<n-1;j++)
    {
        arr[j] = arr[j+1];
    }
    return n-1;
}

int main()
{
    int n, x;
    
    cin>>n;
    int arr[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        arr[i] = temp;
    }
    
    cin>>x;
    cout<<"Old Array: ";
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    int newSize = deleteFromArray(arr, n, x);
    cout<<endl<<"new array: ";
    for (int  i = 0; i < newSize; i++)
    {
        cout<<arr[i]<<" ";
    }
    // cout<<newSize;
    return 0;
}