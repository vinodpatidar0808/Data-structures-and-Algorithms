// left rotate an array by d times

#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// left rotate by 1 place
void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]= arr[i];

    }
    arr[n-1] = temp;
}

// time comp : O(n*d)
void leftRotateNaive(int arr[], int n , int d)
{
    d = d%n;  // d >=n rotating array n times means not rotating it at all. 
    for(int i =0;i<d;i++)
        leftRotateByOne(arr,n);
}

// time comp: O(n), space : O(d)
void leftRotate(int arr[], int n, int d)
{
    int temp[d];
    for(int i=0;i<d;i++)
        temp[i] = arr[i];

    for(int i=d;i<n;i++)
    {
        arr[i-d] = arr[i];
    }

    for(int i=0;i<d;i++)
    {
        arr[n-d+i] = temp[i];
    }

}

void reverseArray(int arr [], int l, int r)
{
    while(l<r)
    {
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

// time comp: O(n), space : O(1)
void leftRotate2(int arr[], int n, int d)
{
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

int main()
{
    int n, d;
    cin>>n>>d;
    d = d%n;
    int  arr[n];
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    cout<<"original array: "<<endl;
    printArray(arr, n);

    // leftRotatByOne(arr,n);
    // leftRotateNaive(arr, n, d);
    // leftRotate(arr, n, d);
    leftRotate2(arr, n, d);

    cout<<endl<<"new array: "<<endl;
    printArray(arr, n);

    return 0;
}