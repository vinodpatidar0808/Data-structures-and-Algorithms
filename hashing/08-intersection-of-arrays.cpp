// find intersection of two arrays, repeating elements not allowed

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std; 

void takeInput(vector<int> &arr, int num)
{
    cout<<"Enter elements of "<<num<<" array"<<endl;
    int size = arr.size();
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<endl;
}

void printArray(vector<int> &arr)
{
    for(auto x: arr)
        cout<<x<<" ";
    cout<<endl;
}

//time:  O(m+n), space : O(m+n)
vector<int> createIntersection(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    vector<int> intersection;
    unordered_set<int> s1(a.begin(), a.end());
    unordered_set<int> s2(b.begin(), b.end());
   
    /*
    for(auto x: a)
        s1.insert(x)
    */
   

    for(auto it : s2)
    {
        if(s1.find(it) != s1.end())
            intersection.push_back(it);
    }

    return intersection;
}


void printIntersection(vector<int> &a, vector<int> &b)
{
    unordered_set<int> s(a.begin(), a.end());
    
    for(auto x: b)
    {
        if(s.find(x) != s.end())
        {
            cout<<x<<" ";
            s.erase(x);
        }
    }
    cout<<endl;
}


int main()
{  
    int m, n;
    cout<<"enter sizes of both arrays "<<endl;
    cin>>m>>n;
    vector<int> a(m);
    vector<int> b(n);
    takeInput(a, 1);
    takeInput(b, 2);

    cout<<"Array 1: "<<endl;
    printArray(a);
    cout<<"Array 2: "<<endl;
    printArray(b);

    cout<<"Intersection of arrays:"<<endl;
    vector<int> res = createIntersection(a,b);
    printArray(res);

    printIntersection(a, b);
    return 0;
}