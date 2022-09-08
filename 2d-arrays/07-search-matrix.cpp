// Search for a value in a row and column wise sorted matrix.


#include <iostream>
#include <vector>
#include <algorithm>


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

// time comp O(n^2)
vector<int> linearSearch(vector<vector<int>> &mat, int val)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans(2, -1);

    bool flag = false;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(mat[i][j] == val)
            {
                flag = true;
                ans[0] = i;
                ans[1] = j;
            }
        if(flag)
            break;
    }
    return ans;
}


// given matrix is sorted row and column wise.
// time comp : O(rows * log(cols))
void searchMatrix(vector<vector<int>> &mat, int val )
{
    int m = mat.size();
    int n = mat[0].size();
    
    vector<int> ans(2, -1);
    if(val< mat[0][0] || val>mat[m-1][n-1])
    {
        cout<<val<<" is not present in the matrix"<<endl;
        return;
    }
    
    for(int i=0;i<m;i++)
    {
        if(val>=mat[i][0] && val<=mat[i][n-1])
        {
            if(binary_search(mat[i].begin(), mat[i].end(), val))
                cout<<val<<" is present in the matrix"<<endl;
            else
                cout<<val<<" is not present in the matrix"<<endl;
            break;
        }
        
    }
}

// time comp : O(rows + cols)

void matrixSearch(vector<vector<int>> &mat, int val)
{
    int m = mat.size();
    int n = mat[0].size();
    int i {0}, j{n-1};

    while(i<m && j>=0)
    {
        if(mat[i][j] == val)
        {
            cout<<val<<" found at ("<<i<<", "<<j<<")"<<endl;
            return ;
        }
        else if(mat[i][j]>val)
        {
            j--;
        }
        else
            i++;
    }
    cout<<val<<" is not present in the matrix"<<endl;
}

int main()
{
    int m, n;
    cout<<"Enter matrix size, rows and columns :"<<endl;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n,0));    
    cout<<"enter matrix values"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    
    int val;
    cout<<"enter value to search:"<<endl;
    cin>>val;

    cout<<"--Original matrix--"<<endl;
    printMatrix(mat);
    
    /*
    vector<int> ans;
    ans = linearSearch(mat, val);
    if(ans[0]!=-1)
        cout<<val<<" found at postion mat["<<ans[0]<<"]["<<ans[1]<<"]"<<endl;
    else
        cout<<"Element does not exist in array"<<endl;
    */

    searchMatrix(mat,val);
    matrixSearch(mat, val);

    return 0;
}