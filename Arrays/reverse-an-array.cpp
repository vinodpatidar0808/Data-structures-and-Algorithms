#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}


void reverseArray(int arr [],int n)
{
    int l {0};
    int r {n-1};
    int temp;
    while(l<r)
    {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }

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

    reverseArray(arr, n);
    cout<<endl;
    cout<<"reversed array :"<<endl;
    printArray(arr, n);

    return 0;
}