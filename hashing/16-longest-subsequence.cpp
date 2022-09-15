// find the length longest subsequence( not subarray) with all consecutive elements (p, p+1, p+2 ....) order not important in original array.

#include <iostream>
#include <algorithm>
#include <unordered_set>


using namespace std; 


// time : O(nlog(n)), space O(1) -> if we are not allowed to modify array then O(n)
int longestSubsequence(int arr[], int n)
{
    int res = 1;
    int curr = 1;
    
    sort(arr, arr+n);
    for(int i=1;i<n;i++)
    {
        if(arr[i] ==  arr[i-1]+1)
            curr++;
        // ignore repeating element
        else if( arr[i]!=arr[i-1])
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    return res;
}


//time : O(n)
int lenLongestSubsequence(int arr[], int n)
{
    unordered_set<int> s(arr,arr+n);
    int res = 1;
    int curr =1;
    for(auto val: s)
    {
        // if val-1 already in set, then we consider val-1 as the beginning of subsequence and ignore val.
        if(s.find(val-1) == s.end())
        {
            curr = 1;
            while(s.find(val+curr) != s.end())
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}



int main()
{
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
        cin>>arr[i++];

    cout<<"Length of longest subsequence with consecutive elements: "<<longestSubsequence(arr, n)<<endl;
    cout<<"Length of longest subsequence with consecutive elements: "<<lenLongestSubsequence(arr, n)<<endl;
    return 0;
}