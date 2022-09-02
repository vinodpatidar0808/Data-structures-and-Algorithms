// check if a given array can be divided into 3 parts with equal sum
// eg. [4,6,5,4,1,0,10]  : yes [4,6], [5,4,1], [0,10] 



#include <iostream>

using namespace std;

bool partsWithEqualSum(int arr[], int n)
{
    int sum {arr[0]} ;
    int prefixSum[n];
    prefixSum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        sum+=arr[i];
        prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    bool flag1 {false}, flag2 {false}, flag3 {false};
    for(int i=0;i<n;i++)
    {
        if(prefixSum[i] == sum/3)
            flag1 = true;
        else if(prefixSum[i] == 2*sum/3)
            flag2 = true;
        else if(prefixSum[i] == sum)
            flag3 = true;
    }
    return flag1 && flag2 && flag3;
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
    cout<<(partsWithEqualSum(arr,n)?"Array can be divided in 3 parts with equal sum...":"Array can not be divided in 3 parts with equal sum...")<<endl;
    return 0;
}