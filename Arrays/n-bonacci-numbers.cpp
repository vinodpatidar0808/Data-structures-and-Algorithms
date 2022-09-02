// N-bonacci numbers:  first N-1 numbers are 0s and Nth number is 1 and next number will be sum of last N numbers. Fibonacci = 2-bonacci 
#include <iostream>
#include <vector>


using namespace std; 

// time comp: O(m) , O(m) space;
void nbonacci(int n, int m)
{
    int arr[m] ;
    for(int i=0;i<n-1;i++)
    {
        arr[i] = 0;
    }
    arr[n-1] = 1;
    int currSum = 1;
    for(int i=n;i<m;i++)
    {
        arr[i] = currSum;
        currSum += arr[i] - arr[i-n];
    }

    for(int i=0;i<m;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void nBonacci(int n, int m)
{
    vector<int> arr(n,0);
    arr[n-1] = 1;
    int i =0;
    while(i<m && i<n)
    {
        cout<<arr[i]<<" ";
        i++;
    }
    int currSum = 1;
    int pointer {0};
    while(i<m)
    {
        int temp = arr[pointer];
        arr[pointer] = currSum;
        cout<<currSum<<" ";
        currSum += arr[pointer] - temp;
        pointer = (pointer + 1)%n;
        i++;
    }
    cout<<endl;
    
}

int main()
{
    
    int n, m; 
    cin>>n;
    cout<<"how many numbers you want to print: "<<endl;
    cin>>m;
    nbonacci(n,m);
    nBonacci(n,m);
    return 0;
}