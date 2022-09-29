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

struct stack{
    Node *head;
    int n;
    stack()
    {
        head = NULL;
        n = 0;
    }

    void push(int d)
    {
        Node *newNode = new Node(d);
        newNode->next = head;
        head = newNode;
        n++;
    }

    int pop()
    {
        if(head == NULL)
            return INT_MIN;
        Node *temp = head;
        head = head->next;
        int res = temp->data;
        delete temp;
        n--;
        return res;
    }    

    int top()
    {
        if(head == NULL)
            return INT_MIN;
        return head->data;
    }

    int size()
    {
        return n;
    }

    bool isEmpty()
    {
        return n == 0;
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    cout<<boolalpha;
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.isEmpty() << endl;
    cout<<s.size() << endl;
    cout<<s.pop() << endl;
    cout<<s.isEmpty() << endl;
    cout<<s.size() << endl;
    return 0;
}