// given an array of non negative integers, values in array are heights of bar, maximum water you can collect between bars?


#include <iostream>
#include <algorithm>

using namespace std;

// time : O(n^2)
int trapWater(int arr [], int n)
{   
    int res = 0;
    // int lmax, rmax;
    // first and last bar cannot hold any water 
    for(int i=1;i<n-1;i++)
    {   
        int lmax = arr[i];
        for(int j=0;j<i;j++)
            lmax = max(lmax, arr[j]);
        int rmax = arr[i];
        for(int j=i+1;j<n;j++)
            rmax = max(rmax, arr[j]);
        
        // cout<<"index "<<i<<" lmax: "<<lmax<<" rmax: "<<rmax<<endl;
        res = res + (min(lmax, rmax) - arr[i]);
        cout<<"water at index "<<i<<": "<<(min(lmax,rmax)-arr[i])<<endl;
    }
    return res;

}

// in previous approach we are computing lmax and rmax in each iteration, to optimize we can precompute lmax and rmax and store them in an array.

int trappingWater(int arr [], int n)
{
    int lmax[n] , rmax[n];
    lmax[0] = arr[0];
    rmax[n-1] = arr[n-1];
    for(int i=1;i<n;i++)
    {
        lmax[i] = max(lmax[i-1], arr[i]);
    }
    for(int i=n-2; i>=0;i--)
    {
        rmax[i] = max(rmax[i+1],arr[i]);
    }

    int maxWater = 0;
    for(int i=1;i<n-1;i++)
    {
        maxWater+= min(lmax[i],rmax[i]) - arr[i];
    }
    return maxWater;
}


void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int n ;
    cin>>n;
    int  arr[n];
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }
    cout<<"original array: "<<endl;
    printArray(arr, n);

    // int maxWater = trapWater(arr, n);
    int maxWater = trappingWater(arr,n);
    cout<<maxWater;
    return 0;
}
