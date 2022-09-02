// 

#include <iostream>

using namespace std;

// time comp: O(n^2)
int maxOnes(int arr[], int n)
{
    int res = 0;
    int curr;
    for(int i=0;i<n;i++)
    {
        curr = 0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1)
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;

}

int maxConsecutives(int arr[], int n)
{
    int res = 0;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            curr++;
            res = max(res, curr);
        }
        else{
            curr=0;
        }
    }
    return res;
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

    // int maxConsecutiveOnes = maxOnes(arr, n);
    int maxConsecutiveOnes = maxConsecutives(arr,n);
    cout<< maxConsecutiveOnes<<endl;
    return 0;
}