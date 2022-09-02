// maximum sum subarray: find the maximum sum of a contiguous subarray

#include <iostream>
#include <limits>

using namespace std;

// time comp: O(n)
int kadane(int arr[], int n)
{
    int maxSum = arr[0];
    int maxEnding = arr[0];

        for(int i=1;i<n;i++)
        {
            maxEnding = max(maxEnding+arr[i],arr[i]);
            maxSum = max(maxSum,maxEnding);
        }

    return maxSum;
}

int maxSum(int arr[], int n)
{
    if(n<1)
        return INT_MIN;
    int res  {arr[0]};
    int curr {0} ;
    for(int i=0;i<n;i++)
    {
        curr = 0;
        for(int j=i;j<n;j++)
        {
            curr+= arr[j];
            res = max(res, curr);
        }
    }
    return res;
    
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
    // cout<<maxSum(arr,n)<<endl;
    cout<<kadane(arr, n)<<endl;
    return 0;
}