// using vector we can make dynamic size stack
#include <iostream>
#include <vector>


using namespace std; 



struct stack{
    vector<int> v;

    void push(int x){
        v.push_back(x);
    }
    int pop(){
        if(v.empty())
            return INT_MIN;        
        int x = v.back();
        v.pop_back();
        return x;
    }
    int size(){
        return v.size();
    }

    int top(){        
        return v.empty() ? INT_MIN : v.back();
    }
    
    bool isEmpty(){
        return v.empty();
    }


};

int main()
{
    stack s;
    s.push(1);
    cout<<boolalpha<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    s.push(0);
    s.push(1);
    cout<<s.size()<<endl;
    cout<<s.isEmpty() << endl;

    return 0;
}