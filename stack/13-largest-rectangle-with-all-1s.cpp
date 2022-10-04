// given a matrix of 1s and 0s find the largest rectangle which has largest area
#include <iostream>
#include <stack>
#include <vector>

#include "getRandomNumber.h"

using namespace std; 

// function prototype
int largestHistogram(vector<int>&arr, int n);

// simple solution generate all matrices from given matrix and check for max area 
// time comp : O(r^3*c^3)

// time comp : O(r*c)
int largestArea(vector<vector<int>> &arr,int r,  int c )
{
    int maxArea= largestHistogram(arr[0],c);
    
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<c;j++)
            if(arr[i][j]==1)
                arr[i][j]+= arr[i-1][j];
        
        maxArea = max(maxArea, largestHistogram(arr[i],c));
    }
    
    return maxArea;
}


int main()
{
    cout<<"enter size of matrix rows and columns respectively"<<endl;
    int r, c;
    cin >> r >> c ;
    vector<vector<int>> arr(r, vector<int>(c, 0));

    for( int i = 0; i < r; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            arr[i][j] = getRandom(0, 2);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"largest area is "<< largestArea(arr,r,c)<<endl;

    return 0;
}


int largestHistogram(vector<int> &arr, int n)
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
