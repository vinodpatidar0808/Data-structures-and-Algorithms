// given an array of n numbers that has values in range (i, n+1) every no. appears exactly once. one no is missing find the missing no.
#include <iostream>

using namespace std;


int missingNumber(int arr[], int n, int start, int end)
{
    // numbers are in range 
    int missingNum = 0;
    for(int i=0 ; i<n ; i++, start++)
    {
        missingNum ^=arr[i]^start;
    }
    missingNum ^=end;
    return missingNum;
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    int start, end ;
    cout<<"Enter ranges values start and end "<<endl;
    cin>>start>>end;

    int n = end - start;
    int  arr[n];
    cout<<"Enter "<<n<<" array values in range "<<start<<" to "<<end<<endl;

    int i = 0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    cout<<"original array: "<<endl;
    printArray(arr, n);

    cout<<"Missing number is: "<<missingNumber(arr,n, start, end)<<endl;
    return 0;
}