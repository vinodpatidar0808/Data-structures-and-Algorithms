// print maximum difference between array element arr[j] - arr[i] where (j > i)

#include <iostream>
#include <vector>
#include <limits>


using namespace std;



void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// time comp: O(n^2)
vector<int> maxDiff(int arr[], int n)
{
    vector<int> res(2, -1); // res contains index i and j if they satisfy the problem requirements. res[0] = i and res[1] = j
    int currMax = INT_MIN;
    int diff ;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            diff = arr[j] - arr[i];
            if(diff>currMax)
            {
                res[0] = i;
                res[1] = j;
                currMax = diff;
            }
        }
    }

    return res;
}


// time comp: O(n)
// to maximize the difference we max on right side and minimum on left side
void maxDiffEfficient(int arr[], int n)
{
    int currMax = arr[1]- arr[0];
    int currMinValue = arr[0];
    for(int i=1;i<n;i++)
    {
        currMax = max(currMax, arr[i] - currMinValue);
        currMinValue = min(currMinValue, arr[i]);
    }

    cout<< currMax;
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

    /*
    if(n>=2)
    {
        vector<int> res = maxDiff(arr,n);
        cout<<"index j is: "<<res[1]<<", index i is: "<<res[0]<<endl;
        cout<<"elements are: "<< arr[res[1]] << " and "<<arr[res[0]]<<" and max difference is: "<<arr[res[1]] - arr[res[0]];
    }
    */
   maxDiffEfficient(arr,n);

    return 0;
}