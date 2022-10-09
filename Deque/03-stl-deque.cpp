#include <iostream>
#include <deque>

using namespace std; 

int main()
{
    deque<int> d {1,2,3};
    d.push_front(8);
    d.push_back(10);
    cout<<d.front()<<endl;
    cout<<d.size()<<endl;
    cout<<d.back()<<endl;
    d.pop_back();
    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    return 0;
}