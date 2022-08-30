#include <iostream>

using namespace std; 

int getLargestIndex(int arr [], int n)
{
    int maxIdx  {0};
    int currMax {arr[0]};
    for(int i=1;i<n;i++)
        if(arr[i]>currMax)
        {
            currMax = arr[i];
            maxIdx = i;
        }

    return maxIdx;

}

int main()
{
    int n ;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    int largest = getLargestIndex(arr, n);
    cout<<"largest element is "<<arr[largest]<<" and located at index "<<largest<<endl;
    return 0;
}