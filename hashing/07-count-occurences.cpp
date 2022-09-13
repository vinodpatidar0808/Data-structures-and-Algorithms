// count occurrence of each  array elements

#include <iostream>
#include <unordered_map>
#include <iterator>


using namespace std; 

// time comp : O(n^2), space : O(1)
void printFrequencies(int arr[], int n)
{
    int count = 1;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        // check if same element has already occured previously
        flag = false;
        for(int j=0;j<i;j++)
        {
            if(arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        count = 1 ;
        for(int j=i+1;j<n;j++)
            if(arr[i]== arr[j])
                count++;
        cout<<arr[i]<<" --> "<<count<<endl;
    }
    cout<<endl;
}


// time O(n) , space: O(n)
void printOccurrences(int arr[], int n)
{
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    
    // unordered_map<int,int>:: iterator itr;
    for(auto it= m.begin();it!=m.end();it++)
        cout<<it->first<<" --> "<<it->second<<endl;
}   

int main()
{
    int arr[] {1,2,1,4,5,7,8,9,1,2,3,4,5,6,4,4,4,4,5,5,5,5,6,7,1,2,3,4,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printFrequencies(arr,n);

    printOccurrences(arr, n);    
    return 0;
}