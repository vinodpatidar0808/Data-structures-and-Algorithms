// given an array not necessarily sorted. Count the inversions in array 
// inversion : A pair arr[i] and arr[j] forms an inversion when (i<j and arr[i] > arr[j])


#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// time comp : O(n)
int inversion(int arr[], int n)
{
    int res = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
                res++;
        }
    }
    return res;
}


// using merge sort's sorting function

int countAndMerge(int arr[], int l, int m, int r)
{
    int n1 {m-l+1}, n2 {r-m};
    int L[n1], R[n2];

    for(int i = 0; i<n1; i++)
        L[i] = arr[i+l];
    for(int j=0;j<n2;j++)
        R[j] = arr[m+1+j];
    
    int res {0}, i {0}, j{0}, k {l};
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++] = L[i++];
        else
        {
            arr[k++] = R[j++];
            res+= n1-i;
        }
    }

    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
        arr[k++] = R[j++];

    return res;
}

int countInversion(int arr[], int l, int r)
{
    if(l>=r)
        return 0;
    int res {0};
    int m = l + (r-l)/2;
    res+=countInversion(arr, l, m);
    res+=countInversion(arr, m+1, r);
    res += countAndMerge(arr, l, m, r);
    return res;
}

int main()
{
    // int arr[] {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[] {10,9,8,7,6,5,4,3,2,1};
    // int arr[] {11,8,2,15,16,7,10,21,14,16,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: "<<endl;
    printArray(arr, n);

    cout<<endl;
    // int res = inversion(arr,n);
    int res = countInversion(arr,0,n-1);
    cout<<"There are \""<<res<<"\" inversions in array."<<endl;
    cout<<endl;
    printArray(arr, n);
        
    return 0;
}