#include <iostream>
#include <queue>

using namespace std; 

int main()
{
    queue<int> q;
    q.push(1); // push == enque 
    cout<<boolalpha;
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty()<<endl;
    q.pop(); // pop == deque
    cout<<q.size()<<endl;
    return 0;
}