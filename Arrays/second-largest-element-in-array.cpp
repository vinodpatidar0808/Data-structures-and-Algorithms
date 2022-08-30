// find the second largest element in array. 

#include <iostream>
#include <array>

using namespace std; 

int secondLargestElement(int arr [], int n)
{
    int idxLargest  {0};
    int idxSlargest {0};
    int largest {arr[0]}; 
    int sLargest {arr[0]}; 
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            sLargest = largest;
            idxSlargest = i;
            largest = arr[i];
            idxLargest = i;
        }
        else if (sLargest < arr[i] && arr[i]<largest)
        {
            sLargest = arr[i];
            idxSlargest = i;
        }
    }
    if(idxLargest == idxSlargest)
        return -1;
    
    return idxSlargest;
}

// better way to write above code 
/*
    largestInd = 0
    largest = arr[0]
    res = -1 // index of second_largest
    iterate from 1 to n-1
    if(arr[i]>largest)
    { 
        res = largestInd;
        largestInd = i;
    }else if (arr[i]!=arr[largest])
    {
        if(res == -1 || arr[i]>arr[res])
            res = i
    }
    return res



*/



int main()
{
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int sLargest = secondLargestElement(arr, n);
    if(sLargest!=-1)
        cout<<"second largest is "<<arr[sLargest]<<" located at "<<sLargest;    
    else
        cout<<"no second largest in the array";
    return 0;
}