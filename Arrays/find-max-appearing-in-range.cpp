/**
 * Problem: You are given 2 arrays as ranges array1[i] = start of range(inclusive), array2[i] = end of range(inclusive).  Find the element which appears maximum number of times in all these ranges. 
*/


#include <iostream>
#include <vector>


using namespace std;

// function prototypes
void printArray(int [], int);

// simple solution : use hashing/maps and count occurrences for each element.

// using prefix-sum technique: works only when given ranges have small values. eg <1000
int maxOccurence(int start [], int end [], int n)
{
    vector<int> arr(1000);

    for(int i=0;i<n;i++)
    {
        arr[start[i]]++;
        arr[end[i]+1]--; // to compensate for prefix sum
    }

    int maxOcc = arr[0], res=0;
    for(int i=1;i<1000;i++)
    {
        arr[i]+=arr[i-1];
        if(maxOcc<arr[i])
        {
            maxOcc = arr[i];
            res = i;
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
    cout<<"size of array: "<<endl;
    cin>>n;
    int  start[n], end[n];
    int i = 0;
    cout<<"Enter start and end range for each array index: "<<endl;
    while(i<n)
    {
        cin>>start[i]>>end[i];
        i++;
    }
    cout<<"original array: "<<endl;
    printArray(start, n);
    printArray(end,n);
     
    int res = maxOccurence(start, end, n);
    cout<<"Maximum occuring element in all ranges is: "<<res<<endl;
    return 0;
}