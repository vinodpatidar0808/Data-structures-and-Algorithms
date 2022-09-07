// given an array of chocolates, and m childrens. Distribute chocolates among childrens such that difference between maximum and minimum chocolates children gets is minimized.
// each child will get only 1 packet

#include <iostream>
#include <algorithm>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

int minDiff(int arr[], int n, int m)
{
    if(m>n)
        return -1;
    sort(arr, arr+n);
    int res = arr[m-1] - arr[0];
    for(int i =1; i<n-m+1;i++)
        res = min(res, arr[i+m-1] - arr[i]);
    return res;
}

int main()
{
    // int arr[] {1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[] {10,9,8,7,6,5,4,3,2,1};
    int arr[] {11,8,2,15,16,7,10,21,14,16,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m;
    cout<<"Enter number of childrens "<<endl; 
    cin>>m;
    cout<<"Original array: "<<endl;
    printArray(arr, n);

    int res = minDiff(arr, n, m);
    cout<<"Minimum difference between chocolates is: "<< res<<endl;
    cout<<endl;

    return 0;
}