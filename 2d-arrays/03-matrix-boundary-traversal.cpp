#include <iostream>
#include <vector>


using namespace std; 


// time complexity: O(rows + cols)
void boundaryTraversal(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    if(rows==1)
    {
        for(int j=0;j<cols;j++)
            cout<<arr[0][j]<<" ";
        cout<<endl;
    }
    else if(cols ==1)
    {
        for(int i=0;i<rows;i++)
            cout<<arr[i][0]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=0; i<cols;i++)
            cout<<arr[0][i]<<" ";
        cout<<endl;
        for(int i=1;i<rows;i++)
            cout<<arr[i][cols-1]<<" ";
        cout<<endl;
        for(int i=cols-2;i>=0;i--)
            cout<<arr[rows-1][i]<<" ";
        cout<<endl;
        for(int i=rows-2;i>0;i--)
            cout<<arr[i][0]<<" ";
        cout<<endl;
    }
}

int main()
{
    int m, n;
    cout<<"Enter matrix size rows and columns in order"<<endl;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));    
    cout<<"enter matrix values"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    cout<<endl;
    cout<<"Boundary traversal "<<endl;
    boundaryTraversal(arr);
    return 0;
}