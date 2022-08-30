// leaders : element which have no greater or equal element on right side is a leader.

#include <iostream>
#include <vector>


using namespace std;



void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}


// time comp: O(n^2)
void leadersNaive(int arr[], int n, vector<int> *leaders)
{
    for(int i =0;i<n;i++)
    {
        bool flag = true;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>=arr[i])
            {
                flag = false; 
                break;
            }
        }
        if(flag)
            leaders->push_back(arr[i]);
    }
}

// time comp: O(n)
// returns leaders in reverse order
void leadersEfficient(int arr[], int n, vector<int> *leaders)
{
    // last element is always a leader
    int currLeader = arr[n-1];  // assuming array have atleast one element, 
    leaders->emplace_back(currLeader);
    for(int i=n-2;i>=0;i--)
    {
        if(currLeader<arr[i])
        {
            currLeader = arr[i];
            leaders->emplace_back(currLeader);
        }
    }
}


int main()
{
    int n ;
    cin>>n;
    int  arr[n];
    vector<int> leaders;
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }
    cout<<"original array: "<<endl;
    printArray(arr, n);

    // leadersNaive(arr, n, &leaders);
    leadersEfficient(arr, n, &leaders);
    cout<<endl;
    cout<<"leader's array :"<<endl;
    // printArray(leaders, n);
    // for(auto val: leaders)
    //     cout<<val<<" ";

    for(auto val = leaders.rbegin(); val!=leaders.rend(); val++)
        cout<<*val<<" ";

    return 0;
}