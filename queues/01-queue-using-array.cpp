#include <iostream>

using namespace std; 

// here deque operation is O(n) time : n current size of queue
// remaining operation are constant time

struct Queue{
    int size, capacity;
    int *arr;
    Queue(int cap)
    {
        size = 0;
        capacity = cap;
        arr = new int[capacity];
    }

    bool isFull() { return size == capacity; }
    
    bool isEmpty() { return size ==0;}

    void enqueue(int d) { 
        if(isFull()) return;
        arr[size++] = d;
    }

    int deque()
    {
        if(isEmpty()) 
            return INT_MIN;
        int res = arr[0];
        for(int i = 1; i<size; i++)
            arr[i-1] = arr[i];
        size--;
        return res;
    }

    int getFront() {
        if(isEmpty()) return INT_MIN;
        return arr[0];
    }

    int getRear() {
        if(isEmpty())
            return INT_MIN;
        return arr[size-1];
    }

    void printQueue()
    {
        if(isEmpty())
            cout<<"Queue is empty!"<<endl;
        else
        {
            cout<<"print queue: ";
            for(int i = 0; i<size; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};



int main()
{

    Queue q(10);

    int input {0};
    cout<<boolalpha;
    while(input != -1)
    {
        cout<<"enter operation number 1 : enque, 2: deque, 3: getFront, 4: getRear, 5: isEmpty, 6: isFull, 7: printQueue: ";
        cin >>input;
        
        if(input == -1)
            break;
        switch (input)
        {
        case 1:
            int x; 
            cout<<"enter number to push: ";
            cin >>x;
            q.enqueue(x);
            break;
        case 2:
            cout<<"Deque: "<<q.deque()<<endl;
            break;
        case 3:
            cout<<"Front: "<<q.getFront()<<endl;
            break;
        case 4: 
            cout<<"Back: "<<q.getRear()<<endl;
            break;
        case 5: 
            cout<<"queue is empty: "<<q.isEmpty()<<endl;
            break;
        case 6:
            cout<<"queue is full: "<<q.isFull()<<endl;
            break;
        default:
            q.printQueue();
            break;
        }
        
    }


    return 0;
}