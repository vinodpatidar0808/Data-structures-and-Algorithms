// given an array and a sum find all subsets from array which sum upto the given sum


#include <iostream>

using namespace std; 


// time comp : O(2^n)
// can be improved using dynamic programming
int countsubsets(int arr[], int n, int  sum)
{
    if(n==0)
        return sum==0?1:0;
    return (countsubsets(arr, n-1,sum) + countsubsets(arr, n-1, sum - arr[n-1]));
}


int main()
{
    int n;
    int arr[n];
    int x ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[i] = x;
    }

    int sum;
    cin>>sum;
    cout<<"Subsets with sum "<<sum<<" in array is :"<<countsubsets(arr, n, sum);
    return 0;
}