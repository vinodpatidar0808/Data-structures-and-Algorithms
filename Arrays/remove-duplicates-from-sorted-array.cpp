
#include <iostream>

using namespace std; 
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// naive solution using additional array for removing duplicates

// time comp : O(n), aux space = O(1)
int removeDuplicates(int arr[], int n)
{
    int currInd = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[currInd])
        {
            currInd++;
            arr[currInd] = arr[i];
        }

    }
    return currInd +1;
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
    
    cout<<"original array:"<<endl;
    printArray(arr,n);

    int newSize = removeDuplicates(arr, n);
    cout<<endl<<"new array:"<<endl;
    printArray(arr, newSize);

    return 0;
}