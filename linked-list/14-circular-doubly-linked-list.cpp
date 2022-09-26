#include <iostream>

using namespace std; 

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


void traverseLinkedList(Node *head)
{
    if(head == NULL)
    {
        cout <<"NULL"<<endl;
        return;
    }
    Node *curr = head;
    do{
        cout<<curr->data<<"<=>";
        curr= curr->next;
    }while(curr != head);
    cout<<"NULL"<<endl;

}


// insertion at beginning of linked list
// time comp : O(1)
Node *insertBegin(Node * head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

Node *insertEnd(Node * head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    newNode->prev->next = newNode;
    head->prev = newNode;
    
    return head;
}

int main()
{
    Node* head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);

    head->next = node1;
    head->prev = node3;
    node1->next = node2;
    node1->prev = head;
    node2->next = node3;
    node2->prev = node1;
    node3->next = head;
    node3->prev = node2;
    
    traverseLinkedList(head);
    // insert at beginning of linked list
    head = insertBegin(head,10);
    head = insertBegin(head,20);
    traverseLinkedList(head); 

    // insert at end of linked list
    head = insertEnd(head,100);
    head = insertEnd(head,200);
    traverseLinkedList(head);

    return 0;
}