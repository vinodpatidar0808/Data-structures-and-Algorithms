// design a data structure with below operations in O(1) time
// insertmin, insert max, get min, get max, extract min, extract max

#include <iostream>
#include <deque>

using namespace std; 

struct minMaxDs{
    deque<int>d;

    void insertmin(int x){
        d.push_front(x);
    }

    void insertMax(int x){
        d.push_back(x);
    }

    int getMin(){
        if(d.empty()) return INT_MIN;
        return d.front();
    }

    int getMax(){
        if(d.empty()) return INT_MIN;
        return d.back();
    }

    int extractMin(){
        if(d.empty()) return INT_MIN;
        int x = d.front();
        d.pop_front();
        return x;
    }

    int extractMax() { 
        if(d.empty()) return INT_MIN;
        int x = d.back();
        d.pop_back();
        return x;
    }

};

int main()
{
    minMaxDs ds;
    ds.insertmin(4);
    ds.insertmin(2);
    ds.insertMax(5);
    ds.insertMax(6);
    cout<<ds.getMin()<<endl;
    cout<<ds.getMax() << endl;
    cout<<ds.extractMin() << endl;
    cout<<ds.extractMax() << endl;
    cout<<ds.getMin()<<endl;
    cout<<ds.getMax() << endl;

    return 0;
}