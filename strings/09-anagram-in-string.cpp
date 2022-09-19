// given a string and a pattern, check if an anagram of pattern is present in string.

#include <iostream>
#include <string>

using namespace std; 

bool areAnagram(string &s, string &pat, int i)
{
    int count[256] = {0};
    int m = pat.length();
    for(int j=0; j<m; j++)
    {
        count[pat[j]]++;
        count[s[i+j]]--;
    }
    for(int j=0;j<256;j++)
    {
        if(count[j] != 0)
            return false;
    }
    return true;
}


// time Comp : O((n-m)*m)
bool searchAnagram(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();
    if(m>n)
        return false;
    for(int i=0; i<=n-m; i++)
    {
        if(areAnagram(s, pat, i))
            return true;
    }
    
    return false;
}


bool areSame(int patCount[], int strCount[])
{
    int size = 256;
    for(int i=0;i<size;i++)
        if(patCount[i] != strCount[i])
            return false;
    return true;
}

// time comp: O(n) 
bool searchAnagram2(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();
    if(m>n)
        return false;

    int patCount[256] = {0};
    int strCount[256] = {0};
    for(int i=0;i<m;i++)
    {
        patCount[pat[i]]++;
        strCount[s[i]]++;
    }
    for(int i=m;i<n;i++)
    {
        if(areSame(patCount, strCount))
            return true;
        strCount[s[i]]++;
        strCount[s[i-m]]--;
    }
    return areSame(patCount, strCount);
    // return false;
}



int main()
{
    string s, pat;
    cout<<"Enter string "<<endl;
    cin>>s;
    cout<<"Enter pattern: "<<endl;
    cin>>pat;
    cout<<boolalpha<<endl;
    cout<<searchAnagram(s, pat)<<endl;
    cout<<searchAnagram2(s, pat)<<endl;

    return 0;
}