#include <iostream>
#include <queue>


using namespace std; 

struct Stack{
    queue<int> q;
    
    int top() {
        if(q.empty()) return INT_MIN;
        return q.front();
    }
    int size() {return q.size();  }


    int pop() { 
        if(q.empty()) return INT_MIN;
        int res = q.front();
        q.pop();
        return res;
    }

    void push(int x) { 
        int size = q.size();
        q.push(x);
        // pushUtil(size);
        pushUtilRecursive(size);
    }

    void pushUtil(int size) {
        int temp ;
        for(int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    // using recursion
    void pushUtilRecursive(int size){
        if(size == 0)
            return ;
        q.push(q.front());
        q.pop();
        pushUtilRecursive(--size);
    }
};

int main()
{
    Stack s;
    cout<<s.size()<<endl;
    s.push(7);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.push(6);
    cout<<s.top() << endl;
    cout<<s.pop() << endl;
    cout<<s.top() << endl;
    cout<<s.top() << endl;
    cout<<s.size()  << endl;
    cout<<s.pop() << endl;
    cout<<s.top() << endl;
    cout<<s.pop() << endl;
    return 0;
}