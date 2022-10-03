// given an array of stock prices for consecutive days
// span of a day: No of consecutive days on left side including current day where price is smaller/equal than current day's price

#include <iostream>
#include <stack>

using namespace std; 

void printSpan(int arr[], int n)
{
    // span of first day is always 1
    int span =1;
    for(int i = 0; i < n; i++)
    {
        span = 1;
        for(int j = i-1; j >= 0 && (arr[j]<=arr[i]) ; j--)
        {
            span++;
        }
        cout<<span<<" ";
    }
    cout<<endl;
}

// using stack and previous greater element 
void printSpan2(int arr[], int n)
{
    // we will store index in stack to get span length
    if(n==0)
        return;
    stack<int> s;
    s.push(0);
    // span of first element
    cout<<1<<" ";
    int span ;
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && arr[s.top()]<=arr[i])
        {
            s.pop();
        }
        span = s.empty() ? i+1: i - s.top();
        cout<<span<<" ";
        s.push(i);
    }
    cout<<endl;
}

int main()
{
    cout<<"enter size of array "<<endl;
    int n;
    cin>>n;
    int arr[n];
    int i = 0;
    while(i<n){
        cin>>arr[i++];
    }

    printSpan(arr, n);
    printSpan2(arr, n);

    return 0;
}