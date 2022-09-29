#include <iostream>
// header file for stack
#include <stack>

using namespace std; 

void print(stack<int> s)
{
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    for(int i = 0; i <10 ; i++)
        s.push(i);
    
    s.emplace(15);
    print(s);

    stack<int> s2 ;
    // s.swap(s2) == s2.swap(s) swaps the content of both stacks
    s.swap(s2);
    // s2.swap(s);
    print(s);
    print(s2);

    return 0;
}