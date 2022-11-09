// given k arrays (sorted) merge them in one sorted array

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 

void printResult(vector<int> &arr)
{
    for(auto val: arr)
        cout<<val<<" ";
    cout<<endl;
}



// easiest solution 
// time comp : O(n*k) , n = maximum number of elements in an array , k number of arrays
vector<int> mergeArrays(vector<vector<int>> &arrays)
{
    vector<int> result;
    int k = arrays.size();
    int n ;
    for(int i = 0; i < k; i++)
    {
        n = arrays[i].size();
        for(int j = 0; j < n; j++)
            result.push_back(arrays[i][j]);
    }

    sort(result.begin(), result.end());
    return result;
}


vector<int> merge(vector<int> &res, vector<int> &arr)
{
    int m = arr.size();
    int n = res.size();
    vector<int> result(m+n);
    int i=0, j=0;
    int ind =0;
    while(i<n && j<m)
    {
        if(res[i]<= arr[j])
            result[ind++] = res[i++];
        else
            result[ind++] = arr[j++]; 
    }

    while(i<n)
    {
        result[ind++] = res[i++];
    }

    while(j<m)
        result[ind++] = arr[j++];
    // printResult(res);
    return result;
}

// using merge sorts merge function
// time comp : O(n*k^2) , n is the number of maximum elements in an array, k number of arrays
vector<int> mergeArrays2(vector<vector<int>> &arrays)
{
    int k = arrays.size();
    int n =arrays[0].size();
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        result.push_back(arrays[0][i]);
    }

    for(int i=1;i<k;i++)
    {
        result = merge(result, arrays[i]);
    }
    return result;
}


// using heap 

struct Triplet{
    // val : array value
    // arrPos : position of array in 2d array
    // valPos : position of val in array
    int val, arrPos, valPos;
    Triplet(int v, int a, int vp)
    {
        val = v;
        arrPos = a;
        valPos = vp;
    }
};

struct myComp{
    bool operator()(Triplet &t1, Triplet &t2){
        return t1.val > t2.val;
    }
};

// time comp : O(n*k*log(k))
vector <int> mergeArrays3(vector<vector<int>> &arrays)
{
    vector<int> result;
    priority_queue<Triplet, vector<Triplet>, myComp> pq;
    
    // k = number of arrays;
    int k = arrays.size();
    for(int i = 0; i < k; i++)
    {
        pq.push(Triplet(arrays[i][0],i,0));
    }

    while(!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        result.push_back(curr.val);
        int arrPos = curr.arrPos, valPos = curr.valPos;
        if(valPos+1 < arrays[arrPos].size())
        {
            pq.push(Triplet(arrays[arrPos][valPos+1], arrPos, valPos+1));
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arrays;
    arrays = {
        {1,3,5, 7,9, 11, 13, 17,21},
        {2,4,6,8,10,12,14,16,18,20,22},
        {4,5,6,7,8,9,10,11,12},
        {1,5,9,11,15,19,23,26,29,31}
    };
    vector<int> res1 = mergeArrays(arrays);
    vector<int> res2 = mergeArrays2(arrays);
    vector<int> res3 = mergeArrays3(arrays);

    printResult(res1);
    printResult(res2);
    printResult(res3);
    
    return 0;
}