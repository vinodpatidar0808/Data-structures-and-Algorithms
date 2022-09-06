#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m- l + 1;
    int n2 = r - m;

    int leftArray[n1];
    int rightArray[n2];
    for(int i=0;i<n1;i++)
        leftArray[i] = arr[l+i];
    for(int j = 0; j<n2; j++)
        rightArray[j] = arr[m + 1 + j];

    int i {0}, j {0}, k {0};
    while(i<n1 && j<n2)
    {
        if(leftArray[i] <= rightArray[j])
            arr[k++] = leftArray[i++];
        else
            arr[k++] = rightArray[j++];
    }   

    while(i<n1)
        arr[k++] = leftArray[i++];
    while(j<n2)
        arr[k++] = rightArray[j++];
    

}

void mergeSort(int arr[],int l, int r)
{
    // equality because we need atleast 2 elements in array
    if(l>=r)
        return ;
    int mid = l + (r-l)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
    
}

int main()
{
    int arr[] {4,5,3,1,2,0,10,11,15,12,10,1,2,9,20,25,24,22,23,2,3};
    // int arr[] {1,2,3,4,5,6,7,8,9,10};
    // int arr[] {10,9,8,7,6,5,4,3,2,1,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array :"<<endl;
    printArray(arr, n);

    
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array:"<<endl;
    printArray(arr, n);

    return 0;
}