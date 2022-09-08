// calculate transpose of a square matrix

#include <iostream>
#include <vector>

using namespace std; 


// here we will compute transpose of matrix assuming that matrix is square.
// for other matrix we will need a matrix of size = cols * rows

void printMatrix(vector<vector<int>> &arr)
{
    for(auto x: arr)
    {
        for(auto i: x)
            cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
}

//time comp: O(n^2 ), O(n^2) space
void transpose(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> temp;
    temp = arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j] = temp[j][i];
    }
}

void transposeInplace(vector<vector<int>> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            swap(arr[i][j],arr[j][i]);
    }
}

int main()
{
    int n;
    cout<<"Enter matrix size rows and columns are same:"<<endl;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));    
    cout<<"enter matrix values"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    cout<<"--Original matrix--"<<endl;
    printMatrix(arr);
    // transpose(arr);
    transposeInplace(arr);
    cout<<"Transpose of array:"<<endl;
    printMatrix(arr);
    return 0;
}