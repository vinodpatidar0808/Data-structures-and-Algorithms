#include <iostream>

using namespace std;

int kadaneMin(int arr[], int n)
{
    int minSum = arr[0];
    int currMinSum = arr[0]; // min sum till current element
    for(int i=1 ;i< n;i++)
    {
        currMinSum = min(currMinSum+arr[i],arr[i]);
        minSum = min(minSum, currMinSum);
    }
    return minSum;

}

int kadaneMax(int arr [], int n)
{
    int maxSum = arr[0];
    int currMaxSum = arr[0]; // max sum till current element
    for(int i=1 ;i< n;i++)
    {
        currMaxSum = max(currMaxSum+arr[i],arr[i]);
        maxSum = max(maxSum, currMaxSum);
    }
    return maxSum;
}


// time comp: O(n)
int maxSum(int arr[], int n)
{
    int maxSum = kadaneMax(arr, n);
    if(maxSum<0)
        return maxSum;

    int arrSum = 0;
    for(int i=0;i<n;i++)
    {
        arrSum+=arr[i];
        // you can do this and use original kadane again to get minsum
        // arr[i] = -arr[i];
    }
    // if array elements are changed
    // int minSum = kadaneMax(arr, n);
    int minSum = kadaneMin(arr, n);

    // if array elements are changed 
    // int maxCircularSum = max(maxSum, arrSum + minSum);
    
    int maxCircularSum = max(maxSum, arrSum - minSum);
    return maxCircularSum;
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
    cout<< maxSum(arr, n);
    return 0;
}