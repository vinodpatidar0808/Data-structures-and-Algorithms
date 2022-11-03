// print ceiling of each element in an array on left side of it, if no ceiling exist print -1, 
// sets and maps use self balancing binary search trees internally 

#include <iostream>
#include <set>

using namespace std; 


// time comp : O(n^2)
void printCeiling(int arr[], int n)
{
    if(n==0)   
        return;
    // first element has no ceil on left side
    cout<<-1<<" ";
    int ceil = INT_MAX;
    for(int i=1; i<n; i++)
    {
        ceil = INT_MAX;
        for(int j=0; j<i;j++)
        {
            if(arr[j] >= arr[i])
                ceil = min(ceil, arr[j]);
        }
        if(ceil == INT_MAX)
            cout<<-1<<" ";
        else
            cout<<ceil<<" ";
    }
    cout<<endl;
}

// using self balancing binary search tree i.e set/maps

void ceiling(int arr[], int n)
{
    if( n == 0 )
        return ;
    set<int> s;
    cout<<-1<<" ";
    s.insert(arr[0]);
    for(int i=1; i<n; i++)
    {
        if(s.lower_bound(arr[i]) !=s.end())
            cout<<*s.lower_bound(arr[i])<<" ";
        else
            cout<<-1<<" ";
        s.insert(arr[i]);
    }
    cout<<endl;

}

int main()
{
    int arr[]  {3,9,29,14,24,12,10,31};
    // int arr[] {1,2,3,4,5,6,7,8,9,10,11,12,13};
    // int arr[] {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    // int arr[] {8,8,9,10,12,10,13,15,12,11,8,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    printCeiling(arr, n);
    ceiling(arr,n);
    return 0;
}