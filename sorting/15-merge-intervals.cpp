// given an array of intervals, merge overlapping intervals in the array.

#include <iostream>
#include <algorithm>

using namespace std; 

// simple solution : O(n^3) 
// O(n^2) : to check an interval for each interval
// O(n) : deleting overlapping interval


struct Interval {
    int s, e;
};


// using sorting O(nlog(n))
bool myComp(Interval a, Interval b)
{
    return a.s <= b.s;
}

int mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr+n, myComp);
    int res {0};
    for(int i=1; i<n;i++)
    {
        if(arr[res].e >= arr[i].s)
        {
            arr[res].e = max(arr[res].e, arr[i].e);
            arr[res].s = min(arr[res].s, arr[i].s);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }
    return res+1;
}



int main()
{
    // Interval arr[] {{2,3},{5,6},{1,7},{8,9},{10,15},{6,10},{7,11}};
    Interval arr[] {{3,4},{4,5},{1,2},{2,4},{9,10}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array"<<endl;
    for(Interval x: arr)
        cout<<"("<<x.s<<" "<<x.e<<") ";

    int newSize = mergeIntervals(arr,n);
    cout<<"After merging: "<<endl;
    for(int i=0;i<newSize;i++)
        cout<<"("<<arr[i].s<<" "<<arr[i].e<<") ";
    
    return 0;
}