#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

// approach 1;
// step 1: store both arrays in one array.
//   step 2 : sort this array
// step : now print elements and skip which are repeated


void printUnion(int a[], int b[], int m, int n)
{
    int i{0}, j{0};
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1])
        {
            i++;
            continue;
        }
        if(j>0 && b[j]==b[j-1])
        {
            j++;
            continue;
        }
        if(a[i] < b[j])
            cout<<a[i++]<<" ";
        else if( a[i]>b[j])
            cout<<b[j++]<<" ";
        else
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }

    }
}

int main()
{
        int a[] {1,2,2,4,5,5,6,7,7,8,8,9,10,15,20,25};
    int b[] {2,2,4,5,6,7,7,8,9,10,10,11,12,13,16,20};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    cout<<"Array 1: "<<endl;
    printArray(a,m);
    
    cout<<"Array 2: "<<endl;
    printArray(b,n);

    cout<<endl;
    cout<<"Union of array:"<<endl;
    printUnion(a,b,m,n);
    

    
    return 0;
}