#include <iostream>
#include <unordered_set>
#include <iterator>


using namespace std; 

int countDistinct(int arr[], int n)
{
    int res = 0; 
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        flag = true;
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            res++;
    }

    return res;
}

int distinctElements(int arr[], int n)
{
    // unordered_set<int> s;
    // for(int i=0;i<n;i++)
    //     s.insert(arr[i]);

    unordered_set<int> s(arr, arr+n);
    return s.size();
}


int main()
{
    int arr[] {1,5,1,4,5,3,12,5,2,3,4,5,6,8,1,5,56,2,1,45,2,1,4,2,35,4,34,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Distinct elements in array: "<<countDistinct(arr,n)<<endl;
    cout<<"Distinct elements in array: "<<distinctElements(arr,n)<<endl;

    
    return 0;
}