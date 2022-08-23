// given a string generate all permutations of given string

#include <iostream>
#include <string>


using namespace std; 

void printPermutations(string s, int ind = 0)
{
    if( ind == s.length() - 1)
    {
        cout<<s<<", ";
        return;
    }

    for(int i = ind ;i< s.length();i++)
    {
        swap(s[i],s[ind]);
        printPermutations(s, ind+1);
        swap(s[i],s[ind]);
    }
}

int main()
{
    string s;
    cin>>s;
    printPermutations(s);    
    return 0;
}