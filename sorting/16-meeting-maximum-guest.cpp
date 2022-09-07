// Given 2 arrays arrivals and departures of guest in a party. party starts at 0 and ends at 2359. maximum guests you can meet at a time. 

#include <iostream>
#include <algorithm>


using namespace std; 

int maxGuest(int arr[], int dep[], int n)
{
    // you can meet atleast meet 1 guest by going on his time.
    sort(arr, arr+n);
    int res {1}, curr{1}; 
    int i {1}, j{0};
    while( i<n && j<n )
    {
        if(arr[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else 
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] {900,940,950,1100,1500,1800,2000,2100};
    int dep[] {910,1200,1120,1130,1900,2000,2220,2150};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = maxGuest(arr, dep, n);
    cout<<"Maximum guest you can meet in the party: "<<res<<endl;
    return 0;
}