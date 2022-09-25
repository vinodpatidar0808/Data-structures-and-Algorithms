// doubly linked list creation and traversal
#include <iostream>

using namespace std; 

struct  Node 
{
    int data; 
    Node * next; 
    Node * prev;
    Node(int d) 
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;

        // data = data;
        // prev = NULL;
        // next = NULL;
    }
};


void traverseLinkedList(Node *head)
{
    Node *temp = head;
    while (temp!= NULL)
    {
        cout << temp->data <<" <==> ";
        temp = temp->next;
    }

    cout <<"NULL"<< endl;
}



int main()
{
    Node * head = new Node(10);
    Node * node1 = new Node(20);
    Node * node2 = new Node(30);
    Node * node3 = new Node(40);

    head->prev = NULL;
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;

    traverseLinkedList(head);
    return 0;
}