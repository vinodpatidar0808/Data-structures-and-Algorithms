// spiral traversal : first row, last column, last row, first column , second row, second last column ........



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

void spiralTraversal(vector<vector<int>>&mat)
{
    int n = mat.size();
    // we maintain 4 different pointers to keep track of rows and columns
    int t {0}, l{0}, r{n-1}, b{n-1};
    while(t<=b && l<=r)
    {
        for(int i=l;i<=r;i++)
            cout<<mat[t][i]<<" ";
        cout<<endl;
        t++;

        for(int i=t;i<=b;i++)
            cout<<mat[i][r]<<" ";
        cout<<endl;
        r--;
        
        if(t<=b)
        {
            for(int i=r;i>=l;i--)
                cout<<mat[b][i]<<" ";
            cout<<endl;
            b--;
        }
        
        if(l<=r)
        {
            for(int i=b;i>=t;i--)
                cout<<mat[i][l]<<" ";
            cout<<endl;
            l++;
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

    spiralTraversal(mat);
    return 0;
}