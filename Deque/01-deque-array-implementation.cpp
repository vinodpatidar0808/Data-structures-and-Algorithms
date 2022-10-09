/**
 *  Deque : Doubly ended queue , where we can insert and remove items from both ends
*/


#include <iostream>

using namespace std; 


// simple implementation, front always at index 0
// insertFront : O(n) time
struct Deque{
    int size, cap;
    int *arr;
    Deque(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    bool isFull() { return size == cap; }
    bool isEmpty() { return size == 0; }

    void insertRear(int x)
    {
        if(isFull()) return;
        arr[size++] = x;
    }

    void insertFront(int x)
    {
        if(isFull()) return;
        for(int i=size-1; i >= 0; i--)
        {
            arr[i+1] = arr[i];
        }

        arr[0] = x;
        size++;
    }

    int popRear()
    {
        if(isEmpty()) return INT_MIN;

        int res = arr[size-1];
        size--;
        return res;
    }
    
    int popFront(){
        if(isEmpty()) return INT_MIN;

        int res = arr[0];
        for(int i=0;i<size-1;i++)
            arr[i] = arr[i+1];
        size--;
        return res;
    }

    int getFront(){
        if(isEmpty()) return INT_MIN;
        return arr[0];
    }
    int getRear()
    {
        if(isEmpty()) return INT_MIN;

        return arr[size-1];
    }

    int getSize(){
        return size;
    }
};

struct Deque2{
    int *arr;
    int front, cap, size;
    Deque2(int c)
    {
        cap = c;
        arr = new int[cap];
        front = 0;
        size = 0;
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }

    void insertRear(int x)
    {
        if(isFull()) return;
        int rear = (front + size) % cap;
        arr[rear] = x;
        size++;
    }

    void insertFront(int x )
    {
        if(isFull()) return;
        front = (front -1 + cap) % cap;
        arr[front] = x;
        size++;
    }

    int getFront(){
        if(isEmpty()) return INT_MIN;
        return arr[front];
    }

    int getRear(){
        if(isEmpty()) return INT_MIN;
        return arr[(front + size -1)%cap];
    }

    int popFront(){
        if(isEmpty())
            return INT_MIN;
        int res = arr[front];
        front = (front+1)%cap;
        size--;
        return res;
    }
    
    int popRear()
    {
        if(isEmpty())   
            return INT_MIN;
        int res = getRear();
        size--;
        return res;
    }
    
    int getSize(){
        return size;
    }

};



int main()
{
    // Deque d(10);
    Deque2 d(10);
    cout<<boolalpha;
    cout<<d.getSize() << endl;
    cout<<d.isEmpty() << endl;
    cout<<d.isFull() << endl;
    d.insertFront(5);
    d.insertRear(10);
    cout<<d.getSize() << endl;
    cout<<d.getFront() << endl;
    cout<<d.getRear() << endl;
    cout<<d.popFront() << endl;
    cout<<d.getFront() << endl;
    cout<<d.getRear() << endl;
    cout<<d.isEmpty() << endl;
    cout<<d.isFull() << endl;
    cout<<d.popRear() << endl;

    return 0;
}