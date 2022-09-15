// count number of distinct elements in each window of size k

#include <iostream>
#include <unordered_map>


using namespace std; 

// time comp: O((n-k)*k*k)
void printDistinctInWindow(int arr[], int n, int k)
{
    int count {0};
    bool repeated = false;
    for(int i=0;i<=n-k;i++)
    {   
        count = 0;
        for(int j=0;j<k;j++)
        {
            repeated = false;
            // check if element a[i+j] appeared earlier 
            for(int l=0;l<j;l++)
            {
                if(arr[i+j] == arr[i+l])
                {
                    repeated = true;
                    break;
                }
            
            }
            if(!repeated)
                count++;
        }
        cout<<"("<<i<<", "<<i+k-1<<"): "<<count<<endl;
    }
    cout<<endl;
}

// 
void printDistinct(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<k;i++)
    {
        m[arr[i]]++;
    }
    cout<<"("<<0<<", "<<k-1<<"): "<<m.size()<<endl;

    for(int i=k;i<n;i++)
    {
        m[arr[i]]++;
        m[arr[i-k]]--;
        if(m[arr[i-k]] == 0)
            m.erase(arr[i-k]);
        cout<<"("<<i-k+1<<", "<<i<<"): "<<m.size()<<endl;
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
    // k<=n
    cout<<"Enter size of window: "<<endl;
    cin>>k;
    printDistinctInWindow(arr,n, k);
    printDistinct(arr,n, k);
    return 0;
}