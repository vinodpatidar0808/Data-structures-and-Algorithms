#include <iostream>
#include <queue>
#include <algorithm>


using namespace std; 

void kLargest(int arr[], int n, int k)
{
    sort(arr, arr+n);
    for(int i=n-1; i>=n-k; i--)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// using maxHeap data structure to print in decreasing order
// time compl : O(n + k*log(n))

void printKLargest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);
    for(int i=0; i<k; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}


// using min heap, prints in reverse order
// time comp : O(k + (n-k)*log(k))
void largestK(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i= 0;i<k;i++)
        pq.push(arr[i]);
    
    for(int i=k; i<n;i++)
    {
        if(arr[i]>=pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;


}

int main()
{
    int arr[] {4,5,7,8,21,5,3,4,6,1,3,4,8,1,11,12,14,51,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // k <= n
    int k = 4;
    kLargest(arr,n,k);
    printKLargest(arr, n,k);
    largestK(arr,n,k);
    return 0;
}