#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>


using namespace std; 

string infixToPrefix(string s)
{
    stack<char> st;
    string prefix;
    char c;
    int n = s.length();
    unordered_map<char,int> precedence = {
    {'^', 3}, {'*',2}, {'/',2}, {'+',1}, {'-',1}};

    for (int i = n-1; i >=0; i--)
    {
        c = s[i];
        if(c == ' ')
            continue;
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            prefix = c + prefix;
        else if(c == ')')
            st.push(c);
        else if(c == '(')
        {
            while(st.empty() && st.top() != ')')
            {
                prefix = st.top() + prefix;
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() &&  precedence[c]<=precedence[st.top()])
            {
                prefix = st.top() + prefix;
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        prefix = st.top() + prefix;
        st.pop();
    }
    return prefix;

}

int main()
{
    cout<<"enter infix string"<<endl;
    string s;
    cin>>s;
    cout<<"infix to prefix : "<<infixToPrefix(s)<<endl;
    return 0;
}