// given an odd sized row-wise sorted matrix, find the median of the matrix



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

float median(vector<vector<int>> &mat)
{
    int m= mat.size();
    int n = mat[0].size();
    int len = m*n;
    int temp[len];
    int ind=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            temp[ind++] = mat[i][j];

    sort(temp, temp + m*n);
    cout<<(float)(5+6)/2<<endl;
    if(len%2 ==0 )
    {
        float val = (float)(temp[(len-1)/2]+temp[len/2]) /2;
        return val; 
    }
    else
        return temp[len/2];
    
}

// median using binary search 
// will work for odd sized matrix only
// for a number to be median n/2 elements must be smaller than this number.
// we can count smaller number using upper_bound which will give us count of number smaller or equal to a number

// time comp: O(rows * log(maxVal-minVal) * log(cols))
int medianBinary(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int minVal = mat[0][0];
    int maxVal = mat[0][n-1];
    // minimum value will lie in first column and max value in last column
    for(int i=1;i<m;i++)
    {
        minVal = min(minVal, mat[i][0]);
        maxVal = max(maxVal, mat[i][n-1]);
    }
    //  medInd = m*n/2 // index
    int medPos = (m*n + 1)/2; // position
    int mid;
    while(minVal< maxVal)
    {
        mid = minVal + (maxVal - minVal)/2;

        int midPos = 0;
        // count number of elements smaller or equal to mid
        for(int i=0;i<m;i++)
            // time comp of upper_bound = O(log(cols))
            midPos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        if(midPos < medPos)
            minVal = mid+1;
        else 
            maxVal = mid;
    }
    return minVal;
}


int main()
{
    int m, n;
    cout<<"Enter size of the matrix: "<<endl;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n,0));
    cout<<"Enter values of matrix in row-wise sorted manner:"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    cout<<"Original matrix:"<<endl;
    printMatrix(mat);

    // float med= median(mat);
    int med = medianBinary(mat);
    cout<<"Median of matrix is: "<<med<<endl;


    return 0;
}