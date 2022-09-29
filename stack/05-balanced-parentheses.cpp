// given a string with only six different characters (, ), {, }, [ and ]. check if parentheses are balanced. 


#include <iostream>
#include <stack>
#include <string>


using namespace std; 

bool isMatching(char a, char b)
{
    if ( (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}') )
        return true;
    return false;
}

bool isBalanced(string &s)
{
    stack<char> st;

    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(' || s[i]=='[' || s[i]=='{')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            if(isMatching(st.top(), s[i]))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}


int main()
{
    cout<<"enter a string of (, ), {, }, [, ]"<<endl;
    string s;
    cin>>s;
    cout<<s<<endl;
    cout<<boolalpha;
    cout<<"string is balanced? "<<isBalanced(s)<<endl;
    return 0;
}