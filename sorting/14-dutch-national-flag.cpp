// sort an array of 3 different types of elements
// 0, 1 and 2
// positive negative and zeroes etc.


#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}


void sortArray(int arr[], int n)
{
    int l {0}, m{0}, h{n-1};
    while(m<=h)
    {
        if(arr[m] == 0)
        {
            swap(arr[m],arr[l]);
            l++;
            m++;
        }
        else if(arr[m] == 1)
            m++;
        else
        {
            swap(arr[m],arr[h]);
            h--;
            // we don't increase m as we don't know what will come at arr[m] after swapping so we have to consider it in next iteration
        }
    }
}

int main()
{
    int arr[] {2,1,0,0,1,2,2,1,0,1,2,0,0,2,1,1,2,0,1,0,2,2,2,0,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);
    sortArray(arr, n);
    cout<<"sorted array:"<<endl;
    printArray(arr,n);
    cout<<endl;

    return 0;
}