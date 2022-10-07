#include <iostream>

using namespace std; 

struct Node {
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue{
    Node *front, *rear;
    int size ;
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int d) {
        Node *temp = new Node(d);
        if(front == NULL) {
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = rear->next;
        }
        size++;
    }

    int deque()
    {
        if(front == NULL) return INT_MIN;
        int res = front->data;
        Node *temp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        delete temp;
        size--;
        return res;
    }

    int getFront()
    {
        if(isEmpty()) return INT_MIN;
        return front->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize(){
        return size;
    }

    void printQueue()
    {
        if(front == NULL)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        Node *curr = front;
        while(curr!= NULL)
        {
            cout<< curr->data<<" ";
            curr = curr->next; 
        }
        cout<<endl;
    }
};


int main()
{
    Queue *q = new Queue();
    q->printQueue();
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->printQueue();
    cout<<q->getFront()<<endl;
    cout<<q->deque()<<endl;
    cout<<q->getFront()<<endl;
    cout<<q->getSize()<<endl;
    
    return 0;
}