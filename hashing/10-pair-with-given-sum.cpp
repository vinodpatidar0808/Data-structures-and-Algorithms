// find a pair with given sum in unsorted array

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std; 

// O(n^2)
bool isPair(int arr[], int n, int sum)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(arr[i] + arr[j] == sum)
                return true;
    }
    return false;
}

// time O(n), space : O(n)
bool pairExist(int arr[], int n, int sum)
{
    // if you do this and then check for sum, you may get incorrect results. 
    // sum = 90, and a element 45 exist in array only once now you will check for 90-45 in set and it will return true;
    // unordered_set<int> s(arr, arr+n);
    
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i]) != s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;
}

void printPairs(int arr[], int n, int sum){
    unordered_map<int, int> map; // value, index

    for(int i=0;i<n;i++)
    {
        if(map.find(sum-arr[i]) != map.end())
            cout<<"("<<i<<", "<<map[sum-arr[i]]<<") ";
        map.insert({arr[i],i});
    }
}

int main()
{
    
    int n;
    cout<<"enter size of array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array values"<<endl;
    int i=0;
    while(i<n)
        cin>>arr[i++];

    cout<<"Enter sum value to check pair"<<endl;
    int sum;
    cin>>sum;
    cout<<boolalpha;
    cout<<"Pair with sum '"<<sum<<"' exists: "<<isPair(arr, n, sum)<<endl;
    cout<<"Pair with sum '"<<sum<<"' exists: "<<pairExist(arr, n, sum)<<endl;
    printPairs(arr, n, sum); 
    return 0;
}