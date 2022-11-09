// given an array as a stream, print median for the stream values
// eg: array  = {1,  4,  5,  6,  7, 8,  9,  10}
//     median = {1, 2.5, 4, 4.5, 5, 5.5, 6, 6.5}

#include <iostream>
#include <queue>
#include <vector>


using namespace std; 

//time comp : O(n^2) 
void printMedian(vector<int> &arr)
{
    // maintaining a sorted array for each value
    vector<int> temp ;

    int n = arr.size();
    int tempSize =0;
    for(int i=0;i<n;i++)
    {
        temp.push_back(arr[i]);
        tempSize++;
        for(int j=tempSize-1;j>0;j--)
        {
            if(temp[j-1] > temp[j])
                swap(temp[j-1],temp[j]);
            else 
                break;
        }

        if(tempSize & 1)
        {
            cout<<temp[tempSize/2]<<" ";
        }
        else{
            float med = (float)(temp[tempSize/2]+temp[(tempSize-1)/2])/2;
            cout<<med<<" ";
        }
    }
    cout<<endl;
}


// using heap
// we maintain 2 containers one for left side and right side of a sorted array. Each container will have equal number of elements when even elements else left container will have one extra element
// time comp : O(nlog(n))

void printMed(vector<int> &arr)
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(arr[0]);
    cout<<arr[0]<<" ";

    int n = arr.size();
    int val ;
    for(int i=1;i<n;i++)
    {
        val = arr[i];
        if(left.size() > right.size())
        {
            if(left.top() > val)
            {
                right.push(left.top());
                left.pop();
                left.push(val);
            }
            else
                right.push(val);
            cout<<(float)(left.top()+right.top())/2<<" ";
        }else{
            if(val <= left.top())
                left.push(val);
            else{
                right.push(val);
                left.push(right.top());
                right.pop();
            }
            cout<<left.top()<<" ";
        }

    }
    cout<<endl;
}

int main()
{
    vector<int> arr {1,4,5,6,7,8,9,};    
    // vector<int> arr {10,6,7,11,9,5,4,12};
    printMedian(arr);    
    printMed(arr);
    return 0;
}