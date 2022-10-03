// given an array, print next greater element of each array element, 
// if next greater does not exist print -1

#include <iostream>
#include <stack>

#include "generateRandomArray.h"


using namespace std;  

// time comp : O(n^2)
void printNextGreater(int arr[], int n)
{
    int nextGreater = -1;
    for (int i = 0; i < n; i++)
    {
        nextGreater = -1;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                nextGreater = arr[j];
                break;
            }
        }
        cout<<nextGreater<<" ";
    }
    cout<<endl;
}


// time comp : O(n), space comp : O(n)
void printNextGreater2(int arr[], int n)
{
    if(n == 0) return;
    stack<int> s;
    s.push(arr[n-1]);
    // int nextGreater = -1;
    // cout<<-1<<" ";
    // this will print nextGreater elements in reverse order
    int nextGreaterArr[n] ;
    nextGreaterArr[n-1] = -1;
    for(int i = n-2; i >= 0; i--)
    {
        while(!s.empty() && s.top()<= arr[i])
            s.pop();
        // nextGreater = s.empty() ? -1 : s.top();
        // cout<<nexGreater<<" ";
        nextGreaterArr[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    printArray(nextGreaterArr, n);

}


int main()
{
    int n ;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    // int i = 0;
    // while(i < n)
    // {
    //     cin>>arr[i++];
    // }

    // generate random array, generateRandomArray takes 4 arguments (arr, size, minValue in array, maxValue in array) -> values of array will be in range [minValue, maxValue)
    generateRandomArray(arr, n, 1, 25 );
    printArray(arr, n);
    printNextGreater(arr, n);
    printNextGreater2(arr, n);

    return 0;
}