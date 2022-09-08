// snake pattern row by row: print first row from left to right, second from right to left and third from left to right and so on


#include <iostream>

using namespace std; 


// time comp: O(rows * columns)
void snakePattern(int *arr[], int m,int n)
{
    cout<<"Matrix in snake pattern"<<endl;
    for(int i=0;i<m;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        }
        else{
            for(int j=n-1;j>=0;j--)
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int m, n;
    cout<<"Enter size of matrix row and column in order"<<endl;
    cin>>m>>n;
    int *arr[m];
    cout<<"Enter array values"<<endl;
    for(int i=0;i<m;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    snakePattern(arr,m,n);
    return 0;
}