// given an array with cost of items (not necessarily sorted), find the maximum number of items you can purchase with a given sum

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

// time comp : O(n*log(n))
int buyMaxItems(int arr[], int n, int sum)
{
    sort(arr, arr+n);
    
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if( arr[i] <= sum )
        {
            res++;
            sum -= arr[i];
        }
        else{
            return res;
        }
    }

    return res;
}

// using min heap
// time comp : O(n+ res*log(n))
int buyMaxItems2(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++)
        pq.push(arr[i]);
    
    int res = 0;
    while(!pq.empty() && pq.top()<=sum)
    {
        res++;
        sum -=pq.top();
        pq.pop();
    }

    return res;

}

int main()
{
    int arr[] {1,4,2,96,3,8,7,10,15,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 40;

    cout<<"max items : "<<buyMaxItems(arr, n, sum)<<endl;
    cout<<"max items : "<<buyMaxItems2(arr, n, sum)<<endl;


    return 0;
}