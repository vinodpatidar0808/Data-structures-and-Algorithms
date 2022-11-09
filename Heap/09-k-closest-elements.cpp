// given an array and 2 numbers k and x, find k closest numbers of x in the array

#include <iostream>
#include <queue>
#include <utility>

using namespace std; 


// time comp : O(nk), aux space : O(n);
void kClosest(int arr[], int n, int k, int x)
{
    bool visited[n] {false};
    for(int i=0;i<k;i++)
    {
        int minDiff = INT_MAX;
        int minDiffInd  ;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && abs(arr[j]-x)<=minDiff)
            {
                minDiff = abs(arr[j]-x);
                minDiffInd = j;
            }
        }
        cout<<arr[minDiffInd]<<" ";
        visited[minDiffInd] =true;
    }
    cout<<endl;
}

struct myComp{
    bool operator()(pair<int,int> const &a, pair<int,int> const &b)
    {
        return a.first <= b.first;

    }
};


// time comp : O(n*log(k))
void printKclosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, myComp> pq;
    for(int i=0;i<k;i++)
        pq.push({abs(x-arr[i]),i});

    int diff ;
    for(int i=k; i<n;i++)
    {
        diff = abs(arr[i]-x);
        if(pq.top().first > diff){
            pq.pop();
            pq.push({diff, i});
        }
    }
    while(!pq.empty())
    {
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main()
{
    int arr[] {1,5,4,2,3,6,7,9,10,15,11,12,17,16,20,25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k {6};
    int x {14};
    kClosest(arr, n, k, x);    
    printKclosest(arr, n, k, x);    
    return 0;
}