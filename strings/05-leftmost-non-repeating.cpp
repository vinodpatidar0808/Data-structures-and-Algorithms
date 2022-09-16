#include <iostream>
#include <string>


using namespace std; 


// time comp: O(n^2)
int leftMostNonRepeating(string &s, int n)
{
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag = false;
        for(int j=0;j<n;j++)
        {
            if(j!=i && s[i] == s[j])
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            return i;
    }
    return -1;
}

int firstNonRepeating(string &s, int n)
{
    int chars[256] ={0};
    for(int i=0;i<n;i++)
        chars[s[i]]++;
    for(int i=0;i<n;i++)
        if(chars[s[i]] == 1)
            return i;
    return -1;
}

int firstNonRepeatingInd(string &s, int n)
{
    int firstInd[256] ;
    // fill method to fill array with single value
    fill(firstInd, firstInd+256, -1);
    int res = INT_MAX;
    for( int i=0;i<n;i++)
    {
        if(firstInd[s[i]] == -1)
            firstInd[s[i]] = i; //repeated
        else
            firstInd[s[i]] = -2;
    }
    for(int i=0;i<256;i++)
    {
        if(firstInd[i] >= 0)
            res = min(res, firstInd[i]);
    }
    return (res == INT_MAX ? -1 : res);
}


void printAns(string &s, int res)
{
    if(res!=-1)
        cout<<"first non-repeating character in '"<<s<<"' is '"<<s[res]<<"' index: "<<res<<endl;
    else
        cout<<"All characters in the string appear more than once..."<<endl;
}

int main()
{
    string s;
    cout<<"Enter string: "<<endl;
    getline(cin, s);
    int n = s.length();
    printAns(s, leftMostNonRepeating(s, n));
    printAns(s, firstNonRepeating(s, n));
    printAns(s, firstNonRepeatingInd(s, n));

    return 0;
}