// Find the length of longest subarray with given sum

#include <iostream>
#include <unordered_map>


using namespace std; 

// time comp: O(n^2)
int longSubarrayWithSum(int arr[], int n, int sum)
{
    int res = 0;
    int currSum = 0;
    for(int i=0;i<n;i++)
    {
        currSum =0;
        for(int j=i;j<n;j++)
        {
            currSum += arr[j];
            if(currSum == sum)
                res = max(res, j-i+1);
        }
    }
    return res;

}

int longSubArrWithSum(int arr[], int n, int sum)
{
    unordered_map<int,int> h;
    int prefSum = 0;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        prefSum += arr[i];
        if(prefSum== sum)
            res = i+1;
        if(h.find(prefSum - sum) != h.end())
            res = max(res, i - h[prefSum-sum]);
        else
            h.insert({prefSum, i});
    }
    return res;
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
    
    int sum ;
    cout<<"Enter value to check "<<endl;
    cin>>sum;

    cout<<boolalpha<<endl;
    cout<<"Length of longest Subarray with sum "<<sum<<" is : "<<longSubarrayWithSum(arr, n, sum)<<endl;
    cout<<"Length of longest subarray with sum "<<sum<<" is: "<<longSubArrWithSum(arr, n, sum)<<endl;        
    return 0;
}