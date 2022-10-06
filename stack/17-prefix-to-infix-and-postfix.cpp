#include <iostream>
#include <stack>
#include <string>

using namespace std; 

string prefixToPostfix(string s)
{
    stack<string> st;
    int n = s.size();
    string postFix ;
    char c;
    for(int i=n-1; i>=0; i--)
    {
        c = s[i];
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string temp = operand1 + operand2 + c;
            st.push(temp);
        }
        else
        {
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}

string prefixToInfix(string s)
{
    stack<string> st;
    int n = s.size();
    char c ;
    for(int i=n-1; i >= 0; i--)
    {
        c = s[i];
        if(c == '+' || c== '-'|| c=='*'|| c == '/')
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string temp = "(" + operand1 + c + operand2 +")";
            st.push(temp);
        }
        else
        {
            st.push(string(1,s[i]));
        }
    }    
    return st.top();
}

int main()
{
    cout<<"enter a prefix string"<<endl;
    string s;
    // cin>>s;
    s = "+x+yz";
    // s = 
    cout<<"Postfix string: "<<prefixToPostfix(s)<<endl;
    cout<<"Infix string: "<<prefixToInfix(s)<<endl;
    return 0;
}