// majority element: an element which appears more than n/2 times

#include <iostream>

using namespace std;


// returns the first index of majority element if exist else return -1
// time comp : O(n^2)
int majorityInd(int arr[], int n)
{
    // for(int i=0;i<n;i++)
    for(int i=0;i<=n/2;i++)
    {
        int count = 1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==arr[i])
                count++;
        }
        if(count>n/2)
            return i;
    }
    return -1;
}

// moore's voting algorithm
// time comp: O(n)

int majIndMoore(int arr[], int n)
{
    int currInd = 0;
    int vote = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[currInd])
            vote++;
        else
            vote--;
        if(vote==0)
        {
            vote = 1;
            currInd = i;
        }
    }
    int count = 0;
    int potentialMajElement = arr[currInd];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==potentialMajElement)
            count++;
    }

    if(count>n/2)
        return currInd;
    return -1;
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
    
    // int majInd = majorityInd(arr, n);
    int majInd = majIndMoore(arr, n);
    if(majInd!=-1)
        cout<<"Index of majority element is: "<<majInd<<" and majority element is "<<arr[majInd]<<endl;
    else    
        cout<<"no majority element in the array";

    return 0;
}