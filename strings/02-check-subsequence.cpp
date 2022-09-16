// check if a string is subsequnce of other string (characters must be same order)
// eg/ s1 = "ABCDE" s2="AD" --> result: true ( s2 subsequence of s1)
// eg/ s1 = "ABCDE" s2="AED" --> result: false ( s2 not a subsequence of s1)

#include <iostream>
#include <string>

using namespace std; 

// simple solution: generating all subsequnces and then checking if the string matches with any of subsequence. time O(2^n * n) : n length of smaller string.


// time comp: O(n)
bool isSubsequence(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();
    if(n<m)
        return false;
    int j =0;
    for(int i=0;i<n && j<<m;i++)
    {
        if(s1[i] == s2[j])
            j++;
    }
    return j==m;
}


// recursive : time comp O(max(m,n))
bool checkSubsequence(string &s1, string &s2, int n, int m)
{
    if(m==0)
        return true;
    if(n==0)
        return false;
    if(s1[n-1]==s2[m-1])
        return checkSubsequence(s1,s2, n-1,m-1);
    else 
        return checkSubsequence(s1,s2, n-1,m);

}


int main()
{
    string s1, s2;
    cout<<"Enter main string: "<<endl;
    getline(cin, s1);
    cout<<"Enter subsequence to check"<<endl;
    getline(cin, s2);
    cout<<boolalpha<<endl;
    cout<<"'"<<s2<<"' a subsequence of '"<<s1<<"' ? "<<isSubsequence(s1,s2)<<endl;
    return 0;
}