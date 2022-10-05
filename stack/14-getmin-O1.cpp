// get minimum value from stack in O(1) time
#include <iostream>
#include <stack>
#include <cstdlib>
#include <time.h>

#include "getRandomNumber.h"

using namespace std; 

// time comp : O(1) for getMin, space comp : O(n)
struct minStack{
    stack<int> mainStack;
    stack<int> auxStack;
    // minStack(){}
    void push(int d)
    {
        mainStack.push(d);
        if(auxStack.empty() || auxStack.top() >= d)
            auxStack.push(d);
    }

    int pop()
    {
        if(auxStack.top() == mainStack.top())
            auxStack.pop();

        int res = mainStack.top();
        mainStack.pop();
        return res;
    }
    int getMin()
    {
        if(auxStack.empty())
            return INT_MIN;
        return auxStack.top();
    }

    bool isEmpty(){
        return mainStack.empty();
    }
};


// works only for positive numbers
// time comp : O(1). space : O(1)
// steps : store min value in a variable currMin
// when you push a value (x) smaller than current minimum , push (x - currMin) 
// update current minimum to value to push ie. currMin = x 
// when you pop a value, it its negative => minimum must have changed here when we pushed 
// currMin = currMin - popped value 

struct minStack2{
    stack<int> st;
    int currMin = INT_MIN;
    void push(int x)
    {
        if(st.empty())
        {
            st.push(x);
            currMin = x;
        }
        else if(x <= currMin)
        {
            st.push(x-currMin);
            currMin = x;
        }
        else
            st.push(x);
    }

    int getMin(){
        return currMin;
    }
    int pop()
    {
        if(st.empty())
            return INT_MIN;
        int t= st.top();
        st.pop();
        if(st.empty())
        {
            currMin = INT_MIN;
            return t;
        }

        if(t <= 0)
        {
            int res = currMin;
            currMin = currMin - t;
            return res;
        }
        else{
            return t;
        }
    }

    int top()
    {
        int t = st.top();
        return t<=0 ? currMin : t;
    }
    bool isEmpty(){
        return st.empty();
    }

};


// this works like above approach but handles negative numbers also.
struct minStack3{
    stack<int> st;
    int currMin = INT_MIN;
    void push(int x)
    {
        if(st.empty())
        {
            st.push(x);
            currMin = x;
        }
        else if(x <= currMin)
        {
            st.push(2*x-currMin);
            currMin = x;
        }
        else
            st.push(x);
    }

    int getMin(){
        return currMin;
    }

    int pop()
    {
        if(st.empty())
            return INT_MIN;
        int t= st.top();
        st.pop();
        if(st.empty())
        {
            currMin = INT_MIN;
            return t;
        }

        if(t <= currMin)
        {
            int res = currMin;
            currMin = 2*currMin - t;
            return res;
        }
        else{
            return t;
        }
    }

    int top()
    {
        int t = st.top();
        return t<=0 ? currMin : t;
    }
    bool isEmpty(){
        return st.empty();
    }

};




int main()
{
    cout <<"enter number of elements you want to insert into stack" << endl;
    int n; 
    cin >> n;

    // minStack st;
    minStack3 st;
    srand(time(0));
    int num ;
    cout<<"Main stack \t Curr minimum"<<endl;
    while(n>0)
    {
        num  = getRandom(1,25);
        st.push(num);
        n--;
        cout<<num<<"\t\t"<<st.getMin()<< endl;
    }
    cout<<"Pop \t Curr minimum"<<endl;
    while(!st.isEmpty())
    {
        cout<<st.pop()<<"\t\t"<<st.getMin()<< endl;
    }
    return 0;
}