// print all elements whose count of occurrences is more than n/k

#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std; 

// time O(n*log(n))
void printMoreThanNbyK(int arr[], int n, int k)
{
    sort(arr, arr+n);
    int i=1;
    int count = 1;
    while(i<n)
    {
        count =1;
        while(i<n && arr[i] == arr[i-1] )
        {
            count++;
            i++;
        }
        if(count>n/k)
            cout<<arr[i-1]<<": "<<count<<endl;
        count = 1;
        i++;
    }
    cout<<endl;
}


// time : O(n) , space O(n)
// becomes inefficient if n/k is very large (n is very high and k is very small)
void printNbyK(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto e: m)
    {
        if(e.second > n/k)
            cout<<e.first<<": "<<e.second<<endl;
    }
    cout<<endl;
}

// optimized : array can have atmost k-1 elements which can occur more than n/k times
void printNbyKOpt(int arr[], int n, int k){
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
            m.insert({arr[i],1});
        else{
            for(auto x: m)
            {
                x.second--;
                if(x.second ==0)
                    m.erase(x.first);
            }
        }
    }

    for(auto x: m)
    {
        if(x.second>n/k)
            cout<<x.first<<" "<<x.second<<endl;
    }

}

int main()
{
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    while(i<n)
        cin>>arr[i++];    
    int k;
    cout<<"Enter value of k"<<endl;
    cin>>k;
    printMoreThanNbyK(arr, n,k);
    printNbyK(arr, n, k);
    printNbyKOpt(arr, n, k);
    return 0;
}