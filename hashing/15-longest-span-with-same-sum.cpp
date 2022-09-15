// given 2 binary arrays of same size find longest with span with same sum in both arrays

#include <iostream>
#include <unordered_map>

using namespace std; 

// O(n^2)
int lenOfLongestSpan(int a[], int b[], int n)
{
    int res = 0;
    int sum1 {0}, sum2 {0};
    for(int i=0;i<n;i++)
    {
        sum1 =0;
        sum2=0;
        for(int j=0;j<n;j++)
        {
            sum1+=a[j];
            sum2+=b[j];
            if(sum1 ==  sum2)
                res = max(res, j-i+1);
        }
    }
    return res;
}

// time: O(n), space: O(n)
int lenSpan(int a[], int b[], int n)
{
    int res =0;
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i] = a[i] -b[i];
    
    // now find length of longest subarray with sum 0 in temp
    unordered_map<int, int> map;
    int prefSum = 0;
    
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



int main()
{
    int arr[]  {1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0};
    int arr2[] {1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Length of longest span with equal sum is : "<<lenOfLongestSpan(arr,arr2, n)<<endl;
    cout<<"Length of longest span with equal sum is : "<<lenSpan(arr,arr2, n)<<endl;

    return 0;
}