#include <iostream>
#include <unordered_set>


using namespace std; 

bool subarrayWithSum(int arr[], int n, int sum)
{
    int currSum = 0;
    for(int i=0;i<n;i++)
    {
        currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(currSum == sum)
                return true;
        }
    }

    return false;
}


bool subArrWithSum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int prefSum =0;
    for(int i=0;i<n;i++)
    {
        prefSum +=arr[i];
        if(prefSum == sum)
            return true;
        if(s.find(prefSum - sum) != s.end())
            return true;
        s.insert(prefSum);
    }    
    return false;
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
    
    int sum ;
    cout<<"Enter value to check "<<endl;
    cin>>sum;

    cout<<boolalpha<<endl;
    cout<<"Subarray with sum "<<sum<<" exists: "<<subarrayWithSum(arr, n, sum)<<endl;
    cout<<"Subarray with sum "<<sum<<" exists: "<<subArrWithSum(arr, n, sum)<<endl;
    return 0;
}