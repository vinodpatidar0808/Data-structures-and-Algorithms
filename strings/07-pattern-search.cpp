// search for a pattern/string in a given string 

#include <iostream>
#include <string>


using namespace std; 

// worst case : when only last character in pattern is different. 
// eg. txt = "AAAAAAAAAAAAAAAAAAAAAAB" pat: = "AAB"

// time comp: O((n-m+1)*m)
void searchPattern(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(s[i+j] != pat[j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
    }
    cout<<endl;
}

// if pattern have all distinct character 
// time : O(n)
void searchPat(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();
    int i=0;
    while(i<n)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(s[i+j] !=  pat[j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else 
            i = i+j;

    }
    cout<<endl;
}

int main()
{
    string s, pattern ;
    cout<<"Enter string :"<<endl;
    getline(cin, s);
    cout<<"Enter pattern to search: "<<endl;
    cin>>pattern;
    searchPattern(s,pattern);
    searchPat(s,pattern);
    return 0;
}