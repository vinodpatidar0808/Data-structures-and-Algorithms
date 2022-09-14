#include <iostream>
#include <unordered_set>


using namespace std;

bool isSubarrayWithZeroSum(int arr[], int n)
{
    int currSum = 0;
    for(int i=0;i<n;i++)
    {
        currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+= arr[j];
            if(currSum == 0)
                return true;
        }
    }
    return false;
}

bool zeroSumSubarray(int arr[], int n)
{
    unordered_set<int> s;
    int prefSum = 0;
    for(int i=0;i<n;i++)
    {
        prefSum+=arr[i];
        if(s.find(prefSum) != s.end())
            return true;
        if(prefSum == 0)
            return true;
        s.insert(prefSum);
    }
    return false;
}

int main()
{
    int n;
    cout<<"enter size of array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array values"<<endl;
    int i=0;
    while(i<n)
        cin>>arr[i++];

    cout<<boolalpha<<endl;
    cout<<"Subarray with zero sum exists: "<<isSubarrayWithZeroSum(arr,n)<<endl;
    cout<<"Subarray with zero sum exists: "<<zeroSumSubarray(arr,n)<<endl;
    return 0;
}