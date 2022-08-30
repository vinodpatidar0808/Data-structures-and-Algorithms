// move all zeroes to the end of array, keeping relative order of remaining elements

#include <iostream>

using namespace std; 


void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// time comp: O(n^2)
void moveAllZeroesNaive(int arr[], int n)
{   
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i+1;j<n;j++)
                if(arr[j]!=0)
                {
                    swap(arr[i],arr[j]);
                    break;
                }   
        }
    }
}

// time comp: O(n)
void moveAllZeroes(int  arr[], int n)
{
    int countNonzero = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[countNonzero]);
            countNonzero++;
        }
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

    // moveAllZeroesNaive(arr,n);
    moveAllZeroes(arr,n);
    cout<<endl<<"new array: "<<endl;
    printArray(arr, n);
    return 0;
}