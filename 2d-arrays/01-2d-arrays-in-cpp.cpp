#include <iostream>
#include <vector>


using namespace std; 

// Standard arrays
void standardArray()
{
    int rows, cols;
    cout<<"Enter size of matrix rows and column in order"<<endl;
    cin>>rows>>cols;
    int arr[rows][cols];
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            arr[i][j] = i+j;
    
    cout<<"Your matrix is "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


// 2d array using double pointers
void doublePointers()
{
    int rows, cols;
    cout<<"Enter size of matrix rows and column in order"<<endl;
    cin>>rows>>cols;
    int **arr;
    arr = new int *[rows];
    for(int i=0;i<rows;i++)
        arr[i] = new int[cols];
    
    cout<<"Double pointer matrix"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j] = i+j;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

// array of pointers
void arrayOfPointers()
{
    int rows, cols;
    cout<<"Enter size of matrix rows and column in order"<<endl;
    cin>>rows>>cols;
    int *arr[rows];

    for(int i=0;i<rows;i++)
        arr[i] = new int[cols];
    
    
    cout<<"Your matrix is "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j] = i+j;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

// array of vectors
void arrayOfVectors()
{
    int rows, cols;
    cout<<"Enter size of matrix rows and column in order"<<endl;
    cin>>rows>>cols;
    vector<int> arr[rows];
    

    cout<<"Your matrix is "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i].push_back(i+j);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;   
}

// vector of vectors
void vectorOfVectors()
{
    int rows, cols;
    cout<<"Enter size of matrix rows and column in order"<<endl;
    cin>>rows>>cols;
    vector<vector<int>> arr;
    
    
    cout<<"Your matrix is "<<endl;
    for(int i=0;i<rows;i++)
    {
        vector<int> temp;
        for(int j=0;j<cols;j++)
        {
            temp.push_back(i+j);
        }
        arr.push_back(temp);
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    cout<<"C++ standard arrays: "<<endl;
    standardArray();
    cout<<"Using double pointers"<<endl;
    doublePointers();
    cout<<"Array of pointers"<<endl;
    arrayOfPointers();
    cout<<"Array of vectors:"<<endl;
    arrayOfVectors();
    cout<<"Vector of vectors"<<endl;
    vectorOfVectors();

    return 0;
}