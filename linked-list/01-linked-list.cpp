// linked list declaration and basic operations

#include <iostream>

using namespace std; 

struct Node
{
    int data;
    // self referential objects (reference object of same type). Every node will store address of a node which is also of same type as node.
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};


void traverseRec(Node *head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    cout<<head->data<<"->";
    traverseRec(head->next);
}

void traverseLinkedList(Node *head)
{

    cout<<"Linked list is :"<<endl;
    Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    // creating a linked list
    Node *head = new Node(10);
    Node *node1 = new Node(11);
    Node *node2 = new Node(12);
    Node *node3 = new Node(13);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    // traversing a linked list
    traverseLinkedList(head);
    traverseRec(head);

    return 0;
}