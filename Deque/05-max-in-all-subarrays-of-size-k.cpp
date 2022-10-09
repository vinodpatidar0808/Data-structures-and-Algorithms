#include <iostream>
#include <deque>
#include <vector>

using namespace std; 


// time comp : O(n*k);
void printMax(int arr[] , int n, int k)
{
    // n-k+1 subarrays
    int currMax ;
    for(int i = 0; i < n-k+1; i++)
    {
        currMax = arr[i];
        for(int j = i+1; j<i+k; j++)
            currMax = max(currMax, arr[j]);
        cout<<currMax<<" ";
    }
    cout<<endl;

}

// time comp : O(n)
vector<int> maxInWindowOfk(int arr[], int n, int k){
    vector<int> result;
    deque<int> d;
    for(int i = 0; i < k; i++)
    {
        while(!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_back(i);
    }

    for(int i=k;i<n;i++)
    {
        result.push_back(arr[d.front()]);
        while(!d.empty() && d.front()<=i-k)
            d.pop_front();
        while(!d.empty() && arr[i]>= arr[d.back()] )
            d.pop_back();
        d.push_back(i);
    }
    result.push_back(arr[d.front()]);
    return result;
}

int main()
{   

    int arr[] = {4,1,2,5,6,3,2,1,7,8,9,5,1,5,15,13,14,20,31};
    // int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14}
    // int arr[] = {10, 9,8,7,6,5,4,3,2,1}
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printMax(arr, n, k);
    vector<int> maxInWindow;
    maxInWindow = maxInWindowOfk(arr, n, k);
    for(auto x: maxInWindow)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}