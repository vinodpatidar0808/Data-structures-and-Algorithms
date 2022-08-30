// assuming we know prices of stocks for upcoming n days and we can buy and sell on any day how to maximize the profit.

#include <iostream>

using namespace std; 

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int maxProfit(int price[], int s, int e)
{   
    if(e<=s)
        return 0;
    int profit = 0;
    for(int i=s;i<e;i++)
    {
        for(int j=i+1;j<=e;j++)
        {
            if(price[j]>price[i])
            {
                int currProfit = price[j]-price[i] + maxProfit(price, s, i-1) + maxProfit(price, j+1, e);
                profit = max(profit, currProfit);
            }
        }
    }
    return profit;
}

// we know prices in advance, so we can purchase at minimum and sell at maximum price

int profitEffiecient(int arr[], int n)
{
    int profit = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            profit+= arr[i] - arr[i-1];
        }
    }
    return profit;
}


int main()
{
    int n ;
    cin>>n;
    int  arr[n];
    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }
    cout<<"original array: "<<endl;
    printArray(arr, n);

    // int profit = maxProfit(arr, 0,n-1);
    int profit = profitEffiecient(arr, n);
    cout<<profit;
    
    return 0;
}