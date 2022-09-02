// given an array of integers and a number K, find the maximum sum of K consecutive elements.

#include <iostream>
#include <limits>

using namespace std;

int maxSumSlidingWindow(int arr[], int n, int k )
{
    int currSum {0};
    int maxSum {0};
    for(int i=0;i<k;i++)
    {
        currSum+=arr[i];
    }
    maxSum = currSum;

    for(int i=k;i<n;i++)
    {
        currSum += arr[i] - arr[i-k];
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int maxSumConsecutive(int arr[], int n, int k)
{
    int maxSum {INT_MIN};
    int currSum {0};
    for(int i=0;i<n-k+1;i++)
    {
        currSum = 0;
        for(int j=0;j<k;j++)
        {
            currSum+=arr[i+j];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}


void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int n,k;
    cin>>n>>k;
    int  arr[n];
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }
    cout<<"original array: "<<endl;
    printArray(arr, n);

    int maxSum = maxSumConsecutive(arr, n, k);
    cout<<maxSum<<endl;
    cout<<maxSumSlidingWindow(arr, n, k);
    return 0;
}