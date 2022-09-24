// find the length of longest substring with distinct characters

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

bool areDistinct(string &s, int i, int j)
{
    vector<bool> visited(256, false);
    for(int k=i;k<=j;k++)
    {
        if(visited[s[k]] == true)
            return false;
        visited[s[k]] = true;
    }    
    return true;
}

// O(n^3)
int lenDistinct(string &s)
{
    int n = s.length();
    int res = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(areDistinct(s,i,j))
                res = max(res, j-i+1);
        }
    }
    return res;
}

// optimizing above approach 
// O(n^2)
int longestDistinct(string &s)
{
    int n = s.length();
    int res = 1;
    for(int i=0;i<n;i++)
    {
        vector<bool> visited(256,false);
        for(int j=i;j<n;j++)
        {
            if(visited[s[j]] == true)
                break;
            else
            {
                res = max(res, j-i+1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
}

// O(n)
int lenLongestDistinct(string s)
{
    int n = s.length();
    int res = 0;
    vector<int> index(256 , -1);
    int i=0;
    for(int j=0;j<n;j++)
    {
        i = max(i, index[s[j]]+1);
        int maxEnd = j - i +1;
        res = max(res, maxEnd);
        index[s[j]] = j;
    }
    return res;
}

int main()
{
    string s;
    cout<<"enter string: "<<endl;
    cin>>s;    
    cout<<"length of longest substring with distinct characters: "<<lenDistinct(s)<<endl;
    cout<<"length of longest substring with distinct characters: "<<longestDistinct(s)<<endl;
    cout<<"length of longest substring with distinct characters: "<<lenLongestDistinct(s)<<endl;

    return 0;
}