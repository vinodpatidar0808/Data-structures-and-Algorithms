// Equilibrium Point : sum of elememts before it, is equal to sum of elements after it.
// a[i] eqm point if sum(a[0],...a[i-1]) = sum(a[i+1]..a[n-1])

#include <iostream>

using namespace std;

void printArray(int [], int );

// simple O(n^2) solution is using 2 loops computing left sum and right sum and then compare

// using prefix sum technique 
// return index of equilibrium point if exist else returns -1
// time comp: O(n)-> 2 traversal , space O(n)
int equilibriumPoint(int arr[], int n)
{
    int prefixSum[n];
    int suffixSum[n];
    prefixSum[0] = arr[0];
    suffixSum[n-1] = arr[n-1];

    for(int i=1;i<n;i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i];
        suffixSum[n-1-i] = suffixSum[n-i] + arr[n-1-i];
    }
    printArray(prefixSum, n);
    printArray(suffixSum, n);

    // corner case: first and last element
    if(suffixSum[1]==0) 
        return 0;
    
    if(prefixSum[n-2]==0)
        return n-1;
    

    for(int i=1;i<n-1;i++)
    {
        if(prefixSum[i-1]==suffixSum[i+1])
            return i;
    }
    return -1;
}


// time O(n) -> 2 traversal, space : O(1)
int equilibrium(int arr[], int n)
{
    int lsum = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        sum -=arr[i];
        if(lsum == sum)
            return i;
        lsum +=arr[i];
    }
    return -1;
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
    cout<<"size of array: "<<endl;
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

    // int res = equilibriumPoint(arr,n);
    int res = equilibrium(arr,n);
    if(res!=-1)
        cout<<"Equilibrium point exist at index: "<<res<<endl;
    else
        cout<<"No equilibrium point in array"<<endl;
    
    return 0;
}