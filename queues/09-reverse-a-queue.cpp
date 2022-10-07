#include <iostream>
#include <queue>
#include <stack>

using namespace std; 

void printQueue(queue<int> q)
{
    cout<<"Queue: ";
    int n = q.size();
    for(int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
}


void reverse(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

}

// recursive solution
void reverseQueue(queue<int> &q)
{
    if(q.empty()) return;

    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}


int main()
{
    queue<int> q;
    cout<<"enter values to insert into queue, enter negative value to exit"<<endl;
    int x = 0;
    while(x >= 0)
    {
        cin>>x;
        if(x <0)
            break;
        q.push(x);
    }
    printQueue(q);
    reverse(q);
    printQueue(q);
    reverseQueue(q);
    printQueue(q);
    
    return 0;
}