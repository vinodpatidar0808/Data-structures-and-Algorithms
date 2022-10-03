// given an array, print next smaller element of each array element, 
// if next smaller does not exist print -1

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stack>

#include "generateRandomArray.h"


using namespace std;  

// time comp : O(n^2)
void printNextSmaller(int arr[], int n)
{
    int nextsmaller = -1;
    for (int i = 0; i < n; i++)
    {
        nextsmaller = -1;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                nextsmaller = arr[j];
                break;
            }
        }
        cout<<nextsmaller<<" ";
    }
    cout<<endl;
}


// time comp : O(n), space comp : O(n)
void printNextSmaller2(int arr[], int n)
{
    if(n == 0) return;
    stack<int> s;
    s.push(arr[n-1]);
    int nextsmallerArr[n] ;
    nextsmallerArr[n-1] = -1;
    for(int i = n-2; i >= 0; i--)
    {
        while(!s.empty() && s.top() >= arr[i])
            s.pop();
        nextsmallerArr[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    printArray(nextsmallerArr, n);

}


int main()
{
    int n ;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];

    // generate random array, generateRandomArray takes 4 arguments (arr, size, minValue in array, maxValue in array) -> values of array will be in range [minValue, maxValue)
    srand(time(0));
    generateRandomArray(arr, n, 1, 25 );
    printArray(arr, n);
    printNextSmaller(arr, n);
    printNextSmaller2(arr, n);

    return 0;
}