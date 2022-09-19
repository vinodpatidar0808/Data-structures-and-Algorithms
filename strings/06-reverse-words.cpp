// reverse words in a given string.
// eg "welcome to github"   --> "github to welcome" 

#include <iostream>
#include <string>
#include <stack>


using namespace std; 

// Time comp:  O(n) , aux space : O(n);
void reverseWords(string &s, int n)
{
    stack<string> st;
    int i=0;
    int start ;
    while(i<n)
    {   
        start = i;
        while(i<n && s[i]=='-')
            i++;
        st.push(s.substr(start, i-start));
        start = i;
        while(i<n && s[i] != '-')
            i++;
        st.push(s.substr(start, i-start));
    }

    s = "";
    while(!st.empty())
    {
        s+=st.top();
        st.pop();
    }
}


void reverse(string &s, int l, int r)
{
    // cout<<l<<" "<<r<<": ";
    while(l<r)
    {
        swap(s[l], s[r]);
        l++; 
        r--;
    }
    // cout<<s<<endl;
}

void reverseWordsInString(string &s, int n)
{
    int start = 0;


    int i=0;
    while(i<n)
    {
        while(i<n && s[i] == '-')
            i++;
        start = i;
        while(i<n && s[i] !='-')
            i++;
        reverse(s, start, i-1);
    }
    reverse(s, 0, n-1);
    // cout<<s<<endl;
}


int main()
{
    string s ;
    cout<<"Enter string :"<<endl;
    // s = "--hello-this-is-a-string-a---b-c-d----";
    getline(cin, s);
    int n = s.length();
    // reverseWords(s,n);
    reverseWordsInString(s,n);
    cout<<"'"<<s<<"'"<<endl;
    return 0;
}