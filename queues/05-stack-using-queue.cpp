#include <iostream>
#include <queue>

using namespace std; 

// in this push operation is costly
struct stack{
    queue<int> q1, q2;
    int top() { return q1.front();}
    int size() { return q1.size();}
    int pop() { 
        int res = q1.front();
        q1.pop();
        return res;
    }
    // costly push operation
    void push(int x) { 
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

// here pop operation is expensive
struct stack2{
    queue<int> q1, q2;
    
    int top() {
        if(q1.empty()) return INT_MIN;
        return q1.back();
    }
    int size() { return q1.size(); }

    void push(int x) {
        q1.push(x);
    }

    int pop() { 
        if(q1.size() == 0)
            return INT_MIN;
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int res = q1.front();
        q1.pop();
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return res;
    }
};

int main()
{
    // stack s;
    stack2 s;

    cout<<s.size() << endl;
    cout<<s.top()<<endl;
    s.push(1);
    cout<<s.size() << endl;
    s.push(2);
    cout<<s.top()<<endl;
    cout<<s.size() << endl;
    cout<<s.pop() << endl;
    cout<<s.size() << endl;
    cout<<s.top()<<endl;
    cout<<s.pop() << endl;
    cout<<s.pop() << endl;
    cout<<s.top()<<endl;
    return 0;
}