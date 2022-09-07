// Given 2 arrays a and b find the intersection of both array.
// only unique elements must be present in intersection

#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    int i = 0;
    while(i<n)
        cout<<arr[i++]<<" ";
    cout<<endl;
}

void printIntersection(int a[], int b[], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=0;j<n;j++)
            if(a[i]==b[j])
            {
                cout<<a[i]<<" ";
                break;
            }
    }
}

void intersection(int a[], int b[], int m, int n)
{
    // using merge function of merge sort, arrays are sorted
    int i {0}, j{0};
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1])
            continue;
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
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
    cout<<"Intersection of array:"<<endl;
    // printIntersection(a,b,m,n);
    intersection(a,b,m,n);


    return 0;
}