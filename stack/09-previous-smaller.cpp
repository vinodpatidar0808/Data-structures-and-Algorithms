#include <iostream>
#include <stack>

using namespace std; 

void printPreviousSmaller(int arr[], int n)
{
    int prevSmaller = -1;
    for (int i = 0; i < n; i++)
    {
        prevSmaller = -1;
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[j] < arr[i])
            {
                prevSmaller = arr[j];
                break;
            }
        }
        cout<<prevSmaller<<" ";
    }
    cout<<endl;
}

void printPreviousSmaller2(int arr[], int n)
{
    if(n == 0) return;
    stack<int> s;
    s.push(arr[0]);
    int prevSmaller = -1;
    cout<<prevSmaller<<" ";
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && s.top() >= arr[i]) 
            s.pop();
        prevSmaller = s.empty() ? -1 : s.top();
        s.push(arr[i]);
        cout<<prevSmaller<<" ";
    }
    cout<<endl;
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

    printPreviousSmaller(arr, n);
    // prevSmaller(arr, n);

    return 0;
}