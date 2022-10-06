#include <iostream>
#include <string>
#include <stack>


using namespace std; 

string postFixToPrefix(string s){
    stack<string> st;
    int n = s.size();
    char c ;
    string prefix ;
    for(int i = 0; i < n; i++){
        c = s[i];
        if(c =='+' || c == '-' || c == '*' || c == '/'){
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string temp = c + operand2 + operand1;
            st.push(temp);
        }
        else{
            st.push(string(1,c));
        }
    }

    while(!st.empty())
    {
        prefix += st.top();
        st.pop();
    }
    return prefix;
}

string postFixToInfix(string s){
        stack<string> st;
    int n = s.size();
    char c ;
    for(int i = 0; i < n; i++){
        c = s[i];
        if(c =='+' || c == '-' || c == '*' || c == '/'){
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string temp = "(" + operand2 + c + operand1 +")";
            st.push(temp);
        }
        else{
            st.push(string(1,c));
        }
    }
    return st.top();
}

int main()
{
    string s;
    // cout<<"enter a postfix string"<<endl;
    // cin>>s;
    s = "xyz++";
    s = "abc*d/+e+";
    cout<<"postfix string: "<<s<<endl;
    cout<<"infix string: "<<postFixToInfix(s)<<endl;
    cout<<"prefix string: "<<postFixToPrefix(s)<<endl;
    return 0;
}