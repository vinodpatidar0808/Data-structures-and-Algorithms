#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

bool checkPalindrome(string &str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    return rev==str;
}   

bool checkIsPalindrome(string &str)
{
    int n = str.length();
    int l {0}, h {n-1};
    while(l<h)
    {
        if(str[l] != str[h])
            return false;
        l++;
        h--;
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter string :"<<endl;
    getline(cin, str);    
    cout<<boolalpha<<endl;
    cout<<str<<" is a palindrome? "<<checkPalindrome(str)<<endl;
    cout<<str<<" is a palindrome? "<<checkIsPalindrome(str)<<endl;

    return 0;
}