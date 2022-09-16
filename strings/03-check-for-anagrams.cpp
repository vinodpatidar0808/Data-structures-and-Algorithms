// anagrams : 2 strings permutation of each other ( frequency of all characters is same, order can be anything)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 


// time comp : O(nlog(n))
bool checkAnagrams(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// time comp: O(max(n, 256)), space : O(256)
bool areAnagrams(string s1, string s2)
{
    // initialize all values to 0, 256 --> total characters
    int chars[256] = {0};
    int n= s1.length();
    int m = s2.length();
    if(n!=m)
        return false;
    for(int i=0;i<n;i++)
    {
        chars[s1[i]]++;
        chars[s2[i]]--;
    }

    for(int i=0;i<256;i++)
        if(chars[i]!=0)
            return false;

    return true;
}


int main()
{
    string s1, s2;
    cout<<"Enter main string: "<<endl;
    getline(cin, s1);
    cout<<"Enter subsequence to check"<<endl;
    getline(cin, s2);
    cout<<boolalpha<<endl;
    cout<<"'"<<s1<<"'"<<" and '"<<s2<<"' anagrams of each other? "<<checkAnagrams(s1, s2)<<endl;
    cout<<"'"<<s1<<"'"<<" and '"<<s2<<"' anagrams of each other? "<<areAnagrams(s1, s2)<<endl;


    return 0;
}