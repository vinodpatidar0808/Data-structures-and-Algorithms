// given an unsorted array of non-negative numbers find a subarray with given sum

#include <iostream>

using namespace std;

// time comp: O(n)
bool subArraySlidingWindow(int arr[], int n, int sum)
{
    int currSum {arr[0]};
    int start {0};

    for(int i=1;i<n;i++)
    {
        while(currSum>sum && start<i)
        {
            currSum -= arr[start];
            start++;
        }
        if(currSum==sum)
        {
            return true;
        }
        currSum+=arr[i];
    }
    return currSum == sum;
}


void subarryWithSum(int arr[], int n, int sum)
{
    int start;
    int currSum {0};
    bool foundSubarray = false;
    for(int i=0;i<n;i++)
    {
        start = i;
        currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(currSum==sum)
            {
                cout<<"subarray with given sum found from index: "<<start<<" to index "<<j<<endl;
                foundSubarray = true;
            }
            else if(currSum>sum)
            // [0 11 0 0 5 6 0 10 1 0] test for array like this
                break;
        }
    }
    if(!foundSubarray)
        cout<<"no subarray found with given sum"<<endl;
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
    int sum ;
    cout<<"expected sum: "<<endl;
    cin>>sum;

    cout<<"original array: "<<endl;
    printArray(arr, n);

    // subarryWithSum(arr, n, sum);
    cout<<subArraySlidingWindow(arr, n, sum);
    return 0;
}