// Problem : generate all subsets of a given string. Assume all characters in string are different

#include <iostream>
#include <string>

using namespace std; 


void subsets(string s, string curr="", int ind=0)
{
    if(ind==s.length())
    {
        cout<<curr<<" ";
        return;
    }
    subsets(s, curr, ind+1); // current element not included in subset 
    subsets(s, curr+s[ind],ind+1);  // current element included in the subset
}

int main()
{

    string s;
    cin>>s;
    subsets(s);
    return 0;
}