#include <iostream>

using namespace std; 



void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// Naive partition : O(n) time but takes 3 traversal, aux space O(n);
// for a random pivot you can pass pivot index in function parameters 
int partitionIndex(int arr[], int l, int h)
{
    int temp[h - l + 1] ;
    int ind {0};
    // picking last element as pivot
    int p = h; 
    // cout<<"pivot is "<<arr[p]<<" index "<<p<<endl;
    int i ;
    for(i=l;i<=h;i++)
    {
        if(arr[i]<=arr[p])
            temp[ind++] = arr[i];
    }
    
    int pi = l+ ind - 1;
    // cout<<"partition index "<<pi<<" partition element "<<temp[pi]<<endl;
    for(int i=l;i<=h;i++)
        if(arr[i]>arr[p])
            temp[ind++] = arr[i];
    
    for(int i=l;i<=h;i++)
        arr[i] = temp[i-l];
    // printArray(temp, h-l+1);
    return pi;
}

// -------------------- Quick sort using lomuto partition -------

// lomuto partition : pivot is always last element
// time O(n) : 1 traversal and O(1) aux space
// when pivot is not last element we can swap pivot with last element than run this algorithm

int lomutoPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l ;

    for(int j=l;j<h;j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[i++],arr[j]);
        }
    }
    swap(arr[i],arr[h]);
    return i;
}


void quickSort(int arr[], int l, int h)
{
    if(l>=h)
        return ;
    // int p = partitionIndex(arr, l, h);
    int p = lomutoPartition(arr, l, h);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, h);
}


// ------------------ quick sort using hoare's partition

// hoare's partition O(n) time and O(1) space
int hoarePartition(int arr[], int l, int h)
{
    // first element as pivot
    int pivot = arr[l];
    int i =l-1, j = h+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<=pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void quickSortHoare(int arr[], int l, int h)
{
    if(l>=h)
        return ;
    // int p = partitionIndex(arr, l, h);
    int p = lomutoPartition(arr, l, h);
    quickSort(arr, l, p);
    quickSort(arr, p+1, h);
}



int main()
{
    int arr[] {4,5,3,1,2,0,10,11,15,12,10,1,2,9,20,25,24,22,23,2,3};
    // int arr[] {1,2,3,4,5,6,7,8,9,10};
    // int arr[] {10,9,8,7,6,5,4,3,2,1,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array :"<<endl;
    printArray(arr, n);

    cout<<"----Quick sort using lomuto partition----"<<endl<<endl;
    quickSort(arr, 0, n-1);
    cout<<"Sorted array:"<<endl;
    printArray(arr, n);    
    cout<<endl;
    cout<<"---Quick sort using Hoare's partition --- "<<endl;
    quickSortHoare(arr, 0, n-1);
    cout<<endl;
    printArray(arr,n);

    return 0;
}