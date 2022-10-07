#include <iostream>

using namespace std; 

// here all operations are in constant time
struct Queue {
    int capacity, size, front; 
    int *arr;
    Queue(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        front = 0;
    }

    bool isFull(){ return size == capacity; }
    bool isEmpty(){ return size == 0; }

    int getFront(){
        if(isEmpty()) return INT_MIN;
        // we are return index here 
        return arr[front];
    }

    int getRearInd(){
        if(isEmpty()) return -1;
        return (front + size -1)%capacity;
    }

    int getRear(){
        if(isEmpty()) return INT_MIN;    
        return arr[getRearInd()];
    }

    void enque(int d){
        if(isFull()) return;
        int rear = getRearInd();
        rear = (rear+1)%capacity;
        arr[rear] =d;
        size++;
    }

    int deque(){
        if(isEmpty())
            return INT_MIN;
        int res = arr[front];
        front = (front+1)%capacity;
        size--;
        return res;
    }


};

int main()
{

    Queue q(10);
    q.enque(1);
    q.enque(2);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getRear() << endl;
    cout<<q.getFront() << endl;

    cout<<q.deque()<< endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    
    return 0;
}