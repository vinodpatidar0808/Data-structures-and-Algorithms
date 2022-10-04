// compute largest area in a histogram , with height of each bar as array element and width is 1 unit
#include <iostream>
#include <stack>
#include <cstdlib>
#include <time.h>

#include "generateRandomArray.h"

using namespace std; 

void getPrevSmallerInd(int arr[], int arr2[], int n);
void getNextSmallerInd(int arr[], int arr2[], int n);

// here we consider each bar as smallest and calculate the area
// time comp: O(n^2)
int getLargestArea(int arr[], int n)
{
    int maxArea = 0;
    int curr ;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        curr = arr[i];
        for(int j = i-1; j >=0; j--)
        {
            if(arr[j] < arr[i])
                break;
            curr+=arr[i];
        }

        for(int j=i+1; j < n; j++)
        {
            if(arr[j] < arr[i])
                break;
            curr+=arr[i];
        }
        maxArea = max(maxArea, curr);
    }
    return maxArea;
}

// in prev approach we were finding previous smaller and next smaller for each element. Here we will precompute both previous and next smaller
// time comp : O(n)
int getLargestArea2(int arr[], int n)
{
    if(n == 0) return 0;
    int maxArea = 0;
    int curr ;
    int prevSmallerInd[n] ;
    int nextSmallerInd[n] ;
    getPrevSmallerInd(arr, prevSmallerInd, n);
    getNextSmallerInd(arr, nextSmallerInd, n);
    // printArray(prevSmallerInd, n);
    // printArray(nextSmallerInd, n);

    for(int i = 0; i < n; i++)
    {
        curr = arr[i];
        curr+= (i-prevSmallerInd[i]-1)*arr[i];
        curr+= (nextSmallerInd[i]-i-1)*arr[i];
        maxArea = max(maxArea, curr);
    }
    
    return maxArea;
}

// 
int getLargestArea3(int arr[], int n)
{
    int maxArea = 0 ;
    int curr;
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        while(!s.empty()&& arr[s.top()] >= arr[i])
        {
            int top = s.top();
            s.pop();
            curr = arr[top]*(s.empty() ? i : (i-s.top()-1));
            maxArea = max(maxArea, curr);
        }
            s.push(i);
    }
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        curr = arr[top]*(s.empty()? n : (n-s.top()-1));
        maxArea = max(maxArea, curr);
    }

    return maxArea;

}


int main()
{
    int n;
    cout<<"Number of elements in the histogram" << endl;
    cin>>n;
    int arr[n];
    generateRandomArray(arr, n, 1, 100);
    printArray(arr, n);

    int largestArea = getLargestArea(arr, n);
    cout<<"Largest area is : "<<largestArea<<endl;

    int largestArea2 = getLargestArea2(arr, n);
    cout<<"Largest area is : "<<largestArea2<<endl;

    int largestArea3 = getLargestArea3(arr, n);
    cout<<"Largest area is : "<<largestArea3<<endl;

    return 0;
}

// utility function to generate previous smaller index and next smaller index

void getPrevSmallerInd(int arr[], int prevSmallerInd[], int n)
{
    prevSmallerInd[0] = -1;
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        prevSmallerInd[i] = s.empty() ? -1: s.top();
        s.push(i);
    }
}

void getNextSmallerInd(int arr[], int nextSmallerInd[], int n)
{
    nextSmallerInd[n-1] = n;
    stack<int> s;
    s.push(n-1);
    for(int i = n-2; i >= 0; i--)
    {
        while(!s.empty() && arr[s.top()] >=arr[i])
            s.pop();
        nextSmallerInd[i] = s.empty() ? n : s.top();
        s.push(i);
    }

}