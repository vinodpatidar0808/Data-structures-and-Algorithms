#include <iostream>

using namespace std; 

struct twoStack{
    int *arr;
    int capacity, top1, top2;
    twoStack(int cap){
        capacity = cap;
        arr = new int[capacity];
        top1 = -1;
        top2 = cap;
    }

    void push1 (int x)
    {
        if(top1 + 1>= top2){
            return ;
        }
        arr[++top1] = x;
    }

    void push2 (int x)
    {
        if(top1 + 1 >= top2){
            return ;
        }
        arr[--top2] = x;
    }

    int pop1()
    {
        if(top1 < 0)
            return INT_MIN;
        int res = arr[top1];
        top1--;
        return res;
    }

    int pop2(){
        if(top2 == capacity)
            return INT_MIN;
        int res = arr[top2];
        top2++;
        return res;
    }

    int peek1()
    {
        if(top1 < 0)
            return INT_MIN;
        return arr[top1];
    }

    int peek2(){
        if(top2 == capacity)
            return INT_MIN;
        return arr[top2];
    }

    int size1(){
        return top1 + 1;
    }
    int size2(){
        return capacity - top2;
    }

    bool isEmpty1()
    {
        return top1 == -1;
    }

    bool isEmpty2()
    {
        return top2 == capacity;
    }
};



int main()
{
    twoStack s(5);
    s.push1(1);
    s.push2(2);
    s.push2(3);
    s.push2(4);
    s.push1(6);

    cout<<boolalpha;
    cout<<s.size1()<< endl;
    cout<<s.size2()<<endl;
    cout<<s.peek1()<< endl;
    cout<<s.peek2()<< endl;
    cout<<s.pop1() << endl;
    cout<<s.pop2() << endl;
    cout<<s.isEmpty1() << endl;
    cout<<s.isEmpty2() << endl;
    cout<<s.pop1() << endl;
    cout<<s.pop2() << endl;
    cout<<s.pop1() << endl;
    cout<<s.isEmpty1() << endl;
    cout<<s.isEmpty2() << endl;

    return 0;
}