// Rotate a square matrix by 90 degrees in anticlock wise direction

#include <iostream>
#include <vector>


using namespace std; 

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

// simple solution : using a temporary matrix O(n^2) time and O(n^2) space.

void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int temp;
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            temp = mat[i][j];
            // move value from right to top
            mat[i][j] = mat[j][n-1-i];
            
            //from bottom to right
            mat[j][n-i-1] = mat[n-1-i][n-1-j];

            // from left to bottom
            mat[n-1-i][n-1-j] = mat[n-j-1][i];

            // assigning temp to left 
            mat[n-j-1][i] = temp;
        }
    }
}

// in-place (anti clockwise) : take transpose of matrix and then reverse individual columns
// for clockwise : take transpose and reverse individual rows
void transpose(vector<vector<int>> &mat)
{
    int n = mat.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            swap(mat[i][j],mat[j][i]);
    }
}

void rotateAntiClockWise(vector<vector<int>> &mat)
{
    transpose(mat);

    int n= mat.size();
    // reversing columns 
    int l {0}, h {n-1};
    for(int i=0;i<n;i++)
    {
        l = 0;
        h = n-1;
        while(l<h)
        {
            swap(mat[l++][i], mat[h--][i]);
        }
    }
}

void rotateClockWise(vector<vector<int>>&mat)
{
    transpose(mat);
    int n = mat.size();
    int l {0}, h{n-1};
    for(int i=0;i<n;i++)
    {
        l = 0 ; 
        h = n-1;
        while(l<h)
        {
            swap(mat[i][l++],mat[i][h--]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter matrix size rows and columns are same:"<<endl;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0));    
    cout<<"enter matrix values"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    cout<<"--Original matrix--"<<endl;
    printMatrix(mat);

    // rotateMatrix(mat);

    rotateAntiClockWise(mat);
    cout<<"Anticlockwise Rotated Matrix:"<<endl;
    printMatrix(mat);

    // rotateClockWise(mat);
    // cout<<"Clockwise Rotated Matrix:"<<endl;
    // printMatrix(mat);
    
    return 0;
}