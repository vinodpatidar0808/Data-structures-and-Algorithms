#include <iostream>

using namespace std; 

// time comp: O(m+n)  : average case
// worst case: O(m*n) : worst case when all character of pattern ans string are same
void searchPattern(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();

    // number of character in string, we take d =256 for all characters
    int d = 256;
    int q = INT_MAX;
    // calculate h=d^(m-1)%q
    int h =1 ;
    for(int i=1;i<m;i++)
        h = (h*d)%q;
    
    int patHash {0}, strHash {0};
    // compute hash for substring of length m and pattern
    for(int i=0;i<m;i++)
    {
        patHash = (d*patHash + pat[i])%q;
        strHash = (d*strHash + s[i])%q;
    }

    // matching pattern
    bool flag = true;
    for(int i=0;i<=n-m;i++)
    {
        if(strHash == patHash)
        flag = true;
        for(int j=0;j<m;j++)
        {
            if(s[i+j] != pat[j])
            {
                flag = false;
                break;
            }
        }    
        if(flag)
            cout<<i<<" ";
        if(i<n-m)
        {
            strHash = (d*(strHash - s[i]*h) + s[i+m])%q;
            if(strHash < 0)
                strHash = strHash + q;
        }
    }


}


int main()
{
    string s, pattern ;
    cout<<"Enter string :"<<endl;
    getline(cin, s);
    cout<<"Enter pattern to search: "<<endl;
    cin>>pattern;
    searchPattern(s, pattern);
    return 0;
}