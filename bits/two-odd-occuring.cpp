// Given an array in which all elements appear even number of times except 2 elements which occur odd number of times. Find these 2 elements.


#include <iostream>

using namespace std;

// time comp: O(n^2)
void twoOddOccuring(int arr[], int twoOdd[], int n)
{
    int count {0};
    int ind = 0;
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
            if(arr[i]==arr[j])
                count++;
        if(count%2==1)
            twoOdd[ind++] = arr[i];
    }

}


// using XOR operator and it's properties
// 1^0 = 0^1 == 1
// 0^0 = 0 and 1^1 = 0
void oddOccuring(int arr[], int twoOdd[], int n)
{
    int xVal = 0;
    for(int i=0;i<n;i++)
        xVal^=arr[i];
    // we pick a set bit from this xVal and divide the array elements in 2 groups. one group with values having this bit set and other with this bit unset.

    // picking right most set bit
    int rmsb = xVal & (~(xVal-1));

    int num1 =0, num2 =0;
    for(int i=0;i<n;i++)
    {
        if((arr[i] & rmsb )!=0)
            num1^=arr[i];
        else
            num2^=arr[i];
    }
    twoOdd[0] = num1;
    twoOdd[1] = num2;

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

    int twoOdd[2] {0,0};
    // twoOddOccuring(arr, twoOdd, n);
    oddOccuring(arr, twoOdd, n);
    cout<<"Two odd occuring elements in array are: "<<twoOdd[0]<<" and "<<twoOdd[1]<<endl;
    
    return 0;

}