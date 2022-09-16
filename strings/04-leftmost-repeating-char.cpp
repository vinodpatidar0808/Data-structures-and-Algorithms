// find the index of leftmost character which repeats in the string

#include <iostream>
#include <string>


using namespace std; 

// time comp : O(n^2), worst case all characters distinct
int indOfFirstRepeating(string s, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(s[i] == s[j])
                return i;
    }
    return -1;
}

// time comp : O(n) 2 traversals
int firstRepeating(string &s, int n)
{
    int chars[256] ={0};
    for(int i=0;i<n;i++)
        chars[s[i]]++;
    for(int i=0;i<n;i++)
        if(chars[s[i]] > 1)
            return i;
    return -1;
}

// time comp O(n) :  1 traversal
int firstRepeatingInd(string &s, int n)
{
    int firstInd[256] ;
    // fill method to fill array with single value
    fill(firstInd, firstInd+256, -1);
    int res = INT_MAX;
    for( int i=0;i<n;i++)
    {
        if(firstInd[s[i]]!=-1)
            res = min(res, firstInd[s[i]]);
        else
            firstInd[s[i]] =  i;
    }
    return (res==INT_MAX?-1: res);
}


// above approach using visited array
int indRepeating(string &s, int n)
{
    bool visited[256] = {false};
    int res {-1};
    for(int i=n-1;i>=0;i--)
    {
        if(visited[s[i]])
            res = i;
        else
            visited[s[i]] = true;
    }
    return res;
}


void printAns(string &s, int res)
{
    if(res!=-1)
        cout<<"first repeating character in '"<<s<<"' is '"<<s[res]<<"' index: "<<res<<endl;
    else
        cout<<"No repeating character in the string..."<<endl;
}


int main()
{
    string s;
    cout<<"Enter string: "<<endl;
    getline(cin, s);
    int n = s.length();
    printAns(s, indOfFirstRepeating(s, n));
    printAns(s, firstRepeating(s, n));
    printAns(s, firstRepeatingInd(s, n));
    printAns(s, indRepeating(s, n));
    return 0;
}