// given 2 sorted arrays merge them in 1 sorted array.



#include <iostream>


using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}


void mergeSorted(int ans[], int a[], int b[], int m, int n, int l)
{
    int i {0}, j {0}, k {0};

    while(i<m && j<n)
    {
        if(a[i]<=b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }
    while(i<m)
        ans[k++] = a[i++];
    while(j<n)
        ans[k++] = b[j++];
}

int main()
{
    int arr[] {5,6,7,8,9,10,12,13,15,16,20,22,25};
    int arr2[] {1,2,4,7,8,10, 11, 14,17,18,19,21,23,24,26,28};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int newSize = m + n;
    int merge[m+n] ;
    mergeSorted(merge, arr, arr2, m, n, m+n);
    printArray(arr,m);
    printArray(arr2,n);
    printArray(merge, newSize);

    return 0;

}