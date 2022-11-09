#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

// priority queue : built on top of vectors

int main()
{
    // this will create a max heap based priority_queue
    priority_queue<int> pq; 

    // for creating min heap  based priority queue
    // you can pass custom comparator function also in place of greater<int>
    priority_queue<int, vector<int>, greater<int>> pqMin ;

    vector<int> v{4,4,1,2,3,4,5,7,6,8,9,10,1,2};
    int arr[] {4,4,1,2,3,4,5,7,6,8,9,10,1,2};
    // priority queue from an existin vector 
    priority_queue<int> pqVect(v.begin(), v.begin()+5);
    // from array 
    priority_queue<int, vector<int>, greater<int>> pqArr(arr, arr+6);

    while(!pqVect.empty())
    {
        cout<<pqVect.top()<<" ";
        pqVect.pop();
    }
    cout<<endl;
    while(!pqArr.empty())
    {
        cout<<pqArr.top()<<" ";
        pqArr.pop();
    }


    return 0;
}