// given a sorted array and a sum find if there is a pair in the array with given sum.

#include <iostream>

using namespace std; 

void pairWithSum(int arr[], int n, int sum)
{
    int l {0}, r {n-1};
    int temp;
    while(l<r)
    {
        temp = arr[l] + arr[r];
        if(temp == sum)
        {
            cout<<"Pair exist with given sum. "<<" index "<<l<<" and index "<<r<<endl;
            return ;
        }
        else if( temp > sum )
            r--;
        else 
            l++;
    }
    if(l==r)
        cout<<"no pair found with given sum"<<endl;
}


int main()
{
    int n ; 
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
        cin>>arr[i++];

    int sum ;
    cout<<"Enter sum "<<endl;
    cin>>sum;
    pairWithSum(arr,n,sum);

    return 0;
}