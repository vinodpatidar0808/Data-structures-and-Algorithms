#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>


using namespace std; 

string infixToPostFix(string s)
{
    stack<char> st;
    int n = s.length();
    string postFix ;
    char c;
    unordered_map<char,int> precedence = {
        {'^', 3}, {'*',2}, {'/',2}, {'+',1}, {'-',1}};

    for (int i = 0; i < n; i++)
    {
        
        c = s[i];
        if(c == ' ')
            continue;
        if((c>='a' && c <= 'z') || (c>='A' && c <= 'Z') || (c>='0' && c <= '9'))
            postFix += c;
        else if( c == '(')
            st.push('(');
        else if( c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postFix += st.top();
                st.pop();
            }
            st.pop();
        }
        else 
        {
            while(!st.empty() && precedence[c] <= precedence[st.top()])
            {
                postFix += st.top();
                st.pop();
            }
            st.push(c);
        }

    }
    while(!st.empty())
    {
        postFix += st.top();
        st.pop();
    }
    return postFix;
}

int main()
{
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    cout<<"postFix expression: "<<infixToPostFix(s)<<endl;

    return 0;
}