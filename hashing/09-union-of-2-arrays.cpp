// find Union of two arrays, repeating elements not allowed

#include <iostream>
#include <set>
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

vector<int> createUnion(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    set<int> s(a.begin(), a.end());
   
    /*
    for(auto x: a)
        s1.insert(x)
    */
   
    for(auto x: b)
        s.insert(x);

    vector<int> unionArray(s.begin(),s.end());

   return unionArray;
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

    cout<<"Union of arrays:"<<endl;
    vector<int> res = createUnion(a,b);
    printArray(res);

    return 0;
}