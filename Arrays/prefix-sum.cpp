// Prefix sum technique: useful in problems like given an array and some queries like getsum(i,j) => i<j etc.

#include <iostream>
// #include <vector>

using namespace std;

int getSum(int prefixSum [], int l, int r)
{
    if(l!=0)
        return prefixSum[r] - prefixSum[l-1];
    return prefixSum[r];

}


void prefixSumArray(int prefixSum [], int arr [], int n)
{
    prefixSum[0] = arr[0];
    for(int i=1;i<n;i++)
        prefixSum[i] = arr[i] + prefixSum[i-1];
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

    int prefixSum[n];
    prefixSumArray(prefixSum, arr, n);

    cout<<"Prefix sum array: "<<endl;
    printArray(prefixSum,n);
    int x,y;
    
    while(true)
    {
        cout<<"enter comma separated query indices or enter a negative number to exit"<<endl;
        cin>>x;
        if(x<0)
        {
            break;
        }
        cin>>y;
        cout<<"sum from index "<<x<<" to index "<<y<<" = "<< getSum(prefixSum,x,y)<<endl;
    }
    
    return 0;
}