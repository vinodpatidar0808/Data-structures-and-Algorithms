// print previous greater element of each element in array
// if no previous greater element print -1;

#include <iostream>
#include <stack>

using namespace std; 

// time comp : O(n^2)
void printPreviousGreater(int arr[], int n)
{
    int prevGreater = -1;
    for(int i=0;i<n;i++)
    {
        prevGreater = -1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] > arr[i])
            { 
                prevGreater = arr[j];
                break;
            }
        }
        cout<<prevGreater<<" ";
    }
    cout<<endl;
}

// time comp : O(n), even when array is sorted
void prevGreater(int arr[], int n)
{
    if(n == 0) return;

    stack<int> s;
    int pg = -1;
    cout<<pg<<" ";
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && s.top() <= arr[i] )
            s.pop();
        pg = s.empty() ? -1: s.top();
        s.push(arr[i]);
        cout<<pg<<" ";
    }
}

int main()
{
    int n ;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    int i = 0;
    while(i < n)
    {
        cin>>arr[i++];
    }

    printPreviousGreater(arr, n);
    prevGreater(arr, n);

    return 0;
}