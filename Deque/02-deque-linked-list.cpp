#include <iostream>

using namespace std; 

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

struct Deque{
    Node *front, *rear;
    int size;
    Deque(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty(){return size == 0;}
    
    int getsize(){return size; }

    void insertFront(int d){
        Node *temp = new Node(d);
        if(front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else 
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        size++;
    }

    void insertRear(int d)
    {
        Node *temp = new Node(d);
        if(front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            temp->prev = rear;
            rear = rear->next;
        }
        size++;
    }

    int getFront()
    {
        if(front == NULL)
            return INT_MIN;
        return front->data;
    }

    int getRear(){
        if(rear == NULL)
            return INT_MIN;
        return rear->data;
    }

    int popFront(){
        if(front == NULL)
            return INT_MIN;
        
        int res;
        size--;
        if(front->next == NULL)
        {
            res = front->data;
            Node *temp = front;
            front=NULL;
            rear=NULL;
            delete temp;
            return res;
        }
        else{
            res = front->data;
            Node *temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
            return res;
        }
    }

    int popRear(){
        if(rear == NULL)
            return INT_MIN;
        int res; 
        size--;
        if(front->next == NULL)
        {
            res = front->data;
            Node *temp = front;
            front=NULL;
            rear=NULL;
            delete temp;
            return res;
        }else
        {
            res = rear->data;
            Node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
            return res;
        }

    }
};


int main()
{
    Deque d;
    cout<<boolalpha;
    cout<<d.getsize() << endl;
    cout<<d.isEmpty() << endl;
    d.insertFront(10);
    d.insertRear(9);
    d.insertFront(8);
    cout<<d.getFront() << endl;
    cout<<d.getRear() << endl;
    cout<<d.getsize() << endl;
    cout<<d.popFront() << endl;
    cout<<d.popFront() << endl;
    cout<<d.popRear() << endl;
    cout<<d.getsize() << endl;

    return 0;
}