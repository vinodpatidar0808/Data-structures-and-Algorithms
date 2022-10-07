#include <iostream>
#include <stack>

using namespace std; 

struct Queue{
    stack<int> s;

    bool empty(){ return s.empty();}

    int size(){ return s.size();}

    int front(){
        if(s.empty()) return INT_MIN;
        return s.top();   
    }

    int deque(){
        if(s.empty()) return INT_MIN;
        int res = s.top();
        s.pop();
        return res;
    }

    void enque(int d){
        if(s.empty())
        {
            s.push(d);
            return;
        }

        int temp = s.top();
        s.pop();
        enque(d);
        s.push(temp);
    }

};

int main()
{
    Queue q;
    cout<<boolalpha;
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.enque(8);
    cout<<q.front()<< endl;
    cout<<q.size() << endl;
    q.enque(10);
    cout<<q.front()<< endl;
    cout<<q.size() << endl;
    cout<<q.empty() << endl;
    cout<<q.front() << endl;
    cout<<q.deque() << endl;
    cout<<q.front() << endl;
    cout<<q.size() << endl;
    cout<<q.deque()<< endl;
    cout<<q.front() << endl;
    cout<<q.size() << endl;
    cout<<q.empty() << endl;

    return 0;
}