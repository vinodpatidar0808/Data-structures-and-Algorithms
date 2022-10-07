#include <iostream>
#include <stack>

using namespace std; 

// enque operation costly
struct Queue{
    stack<int> s1, s2;

    int front(){
        if(s1.empty()) return INT_MIN;
        return s1.top();
    }
    bool empty(){ return s1.empty(); }

    int deque()
    {
        if(s1.empty()) return INT_MIN;
        int res = s1.top();
        s1.pop();
        return res;
    }
    void enque(int d)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(d);
        while(!s2.empty())
        {
            s1.push(s2.top()); 
            s2.pop();
        }
    }
};


// pop operation costly

struct Queue2{
    stack<int> s1, s2;
    int frontElement = INT_MIN;
    int front(){
        return frontElement;
    }

    bool empty() {return s1.empty();}

    void enque(int d)
    {
        s1.push(d);
        if(frontElement == INT_MIN)
            frontElement = d;
    }

    int deque() {
        if(s1.empty())
            return INT_MIN;
        int res;
        if(s1.size() == 1)
        {
            frontElement = INT_MIN;
        }

        while(s1.size() >1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        res = s1.top();
        s1.pop();
        bool flag = true;
        while(!s2.empty())
        {
            s1.push(s2.top());
            if(flag)
            {
                frontElement = s2.top();
                flag = false;
            }
            s2.pop();
        }
        return res;
    }

};

int main()
{
    Queue2 q;
    cout<<boolalpha<<endl;
    cout<<q.front()<< endl;
    cout<<q.empty()<<endl;
    q.enque(6);
    cout<<q.front()<< endl;
    q.enque(8);
    cout<<q.front()<< endl;
    cout<<q.deque() << endl;
    cout<<q.empty() << endl;
    cout<<q.front() << endl;
    cout<<q.deque() << endl;
    cout<<q.front() << endl;
    
    return 0;
}