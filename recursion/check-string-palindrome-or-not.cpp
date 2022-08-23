// problem : given a string check whether it is a palindrome or not 


#include <iostream>
#include <string>


using namespace std; 

bool isPalindrome(string s, int l, int r)
{
    if(l>=r)
        return true;
    if(s[l]!=s[r])
        return false;
    return isPalindrome(s, l+1, r-1);
}

int main()
{
    string s, res;
    cin>>s;
    res = s+" is " + (isPalindrome(s,0,s.length()-1)?"a palindrome string.":"not a palindrome string.");
    cout<<res;
    return 0;
}