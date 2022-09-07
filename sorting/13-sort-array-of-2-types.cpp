// Sort an array of 2 different types of elements.
// negative positive
// binary array
// even odd array and many more.

#include <iostream>

using namespace std; 

// simple solution : 3 traversal of original array
// create a temporary array, now traverse original array and fill negative/0/even in temporary
// again traverse original arary and fill positive/1/odd 
// now put all elements from temp to original array.


void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// using partition algorithm of quicksort (hoare's partition)

// time comp O(n);
void segregatePosNeg()
{
    cout<<"----positive and negative----"<<endl;
    int arr[] {10,11,-10,-20,1,2,-5,-7,0,9,10,26,-9,-8,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array"<<endl;
    printArray(arr,n);
    int i {0}, j{n-1};
    while(true)
    {
        while(arr[i]<0)
            i++;
        while(arr[j]>=0)
            j--;
        if(i>=j)
            break ;
        swap(arr[i],arr[j]);
    }
    cout<<"new array"<<endl;
    printArray(arr, n);
    cout<<endl;
}

void segregateEvenOdd()
{
    cout<<"----Even and Odd----"<<endl;
    int arr[] {3,5,4,7,8,9,1,0,5,6,41,45,78,25,26,36,15,1,71,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array"<<endl;
    printArray(arr,n);
    int i {0}, j{n-1};
    while(true)
    {
        while(arr[i]%2==0)
            i++;
        while(arr[j]%2==1)
            j--;
        if(i>=j)
            break ;
        swap(arr[i],arr[j]);
    }
    cout<<"new array"<<endl;
    printArray(arr, n);
    cout<<endl;
}

// binary array
void segregateBinary()
{
    cout<<"----zeroes and ones----"<<endl;
    int arr[] {0,1,1,1,1,0,1,0,1,0,1,1,1,0,0,1,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"original array"<<endl;
    printArray(arr,n);
    int i {0}, j{n-1};
    while(true)
    {
        while(arr[i]==0)
            i++;
        while(arr[j]==1)
            j--;
        if(i>=j)
            break ;
        swap(arr[i],arr[j]);
    }
    cout<<"new array"<<endl;
    printArray(arr, n);
    cout<<endl;
}

int main()
{
    segregatePosNeg();
    segregateEvenOdd();
    segregateBinary();
    return 0;
}