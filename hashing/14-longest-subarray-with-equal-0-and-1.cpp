// find the length of longest subarray with equal number of 0's and 1's in it.

#include <iostream>
#include <unordered_map>


using namespace std; 

// time : O(n^2)--> we check each subarray for equal 0's and 1's
int longestSubarr(int arr[], int n)
{
    int res = 0;
    int c0 , c1;
    for(int i=0;i<n;i++)
    {
        c0=0;
        c1=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j] == 0)
                c0++;
            else
                c1++;
            if(c0==c1)
                res = max(res, c0+c1);
        }
    }
    return res;
}


// time : O(n) : O(n)
// here we convert each 0 to -1 and now we look for longest subarray with sum=0
int longestSubArray(int arr[], int n)
{
    unordered_map<int,int> map;
    int prefSum=0;
    int res = 0;
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i] = arr[i] == 0 ? -1 : 1;
    for(int i=0;i<n;i++)
    {
        prefSum+= temp[i];
        if(prefSum == 0)
            res = i+1;
        if(map.find(prefSum) != map.end())
            res = max(res, i-map[prefSum]);
        else
            map.insert({prefSum, i});
    }
    return res;
}

// optimizing previous approach
int longSubArr(int arr[], int n)
{
    unordered_map<int,int> map;
    int prefSum=0;
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
        prefSum+= (arr[i]==0 ?- 1 : 1);
        if(prefSum == 0)
            res = i+1;
        if(map.find(prefSum) != map.end())
            res = max(res, i-map[prefSum]);
        else
            map.insert({prefSum, i});
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

    cout<<boolalpha<<endl;
    cout<<"Length of longest Subarray with equal 0's and 1's is : "<<longestSubarr(arr, n)<<endl;
    cout<<"Length of longest subarray with equal 0's and 1's is : "<<longestSubArray(arr, n)<<endl;        
    cout<<"Length of longest subarray with equal 0's and 1's is : "<<longSubArr(arr, n)<<endl;        
    return 0;
}