// sort k sorted arrays (somewhat sorted) 
// k sorted : an element at index i will be present between index i-k and i+k in the sorted array


#include <iostream>
#include <queue>

using namespace std; 

// approach 1 : ;simply sort the array

// time comp : O((n+k)*log(k))
void sortKsorted(int arr[], int n,int k)
{

    // min heap based for sorting in ascending order, max heap based for sorting in descending order
    priority_queue<int, vector<int>, greater<int>> pq;


    for(int i = 0; i <=k;i++)
    {
        pq.push(arr[i]);
    }

    int ind =0;
    for(int i=k+1;i<n;i++)
    {
        arr[ind++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty())
    {
        arr[ind++] = pq.top();
        pq.pop();
    }
}


void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    // int arr[] {9,8,7,18,19,17};
    // int k = 2;
    
    int arr[] {10,9,7,8,4,70,50,60};
    int k = 4;

    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    sortKsorted(arr, n, k);
    printArray(arr, n);

    return 0;
}