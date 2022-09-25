#include <iostream>

using namespace std; 

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void traverseLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data <<" <==> ";
        curr = curr->next;
    }

    cout <<"NULL"<< endl;
}

// insert a node at the beginning of the linked list
// time comp: O(1) 
Node* insertNodeBegin(Node* head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    return newNode;
}


// insert a node at the end of the linked list
// time comp: O(n)
Node *insertNodeEnd(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == NULL)
        return newNode;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}


int main()
{

    Node *head = new Node(10);
    Node *node1 = new Node(11);
    Node *node2 = new Node(12);

    head->prev = NULL;
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = NULL;
    traverseLinkedList(head);

    head = insertNodeBegin(head, 100);
    head = insertNodeBegin(head, 200);
    head = insertNodeBegin(head, 300);
    traverseLinkedList(head);

    head = insertNodeEnd(head, 500);
    head = insertNodeEnd(head, 600);

    traverseLinkedList(head);
    
    return 0;
}