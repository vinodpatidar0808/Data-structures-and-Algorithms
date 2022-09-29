#include <iostream>

using namespace std; 

struct stack{
    int *arr;
    int ind;
    int capacity;
    stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];
        ind = -1;
    }

    void push(int x)
    {
        if(ind == capacity-1)
            return ;
        ind++;
        arr[ind] = x;
    }     

    int pop()
    {
        if(ind == -1)
            return INT_MIN;
        int res = arr[ind--];
        return res;
    }

    int top()
    {
        if(ind == -1)
            return INT_MIN;
        return arr[ind];
    }

    int size(){
        return ind+1;
    }

    bool isEmpty(){
        return ind == -1;
    }

};

int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<boolalpha<<endl;
    cout<<s.pop()<<endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    s.push(10);
    cout<<s.pop()<<endl;
    cout<<s.top() << endl;


    return 0;
}