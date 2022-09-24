/*** Insertion in the linked list , 3 cases
 *  1. in the beginning
 *  2. at the end of LL
 *  3. at a given position
 */

#include <iostream>

using namespace std; 

struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

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

// inserting at the beginning
// time comp : O(1)
Node *insertBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

// inserting at the end
// time comp : O(n):  n = size of linked list
Node *insertEnd(Node * head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
        return newNode;
    Node *curr = head ;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}


// inserting at a given position (position starts from 1)
// time comp : O(n) : worst case when position > size
Node *insertAtPosition(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    if(pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;
    for(int i=1;i<pos-1 && curr!=NULL ; i++)
    {
        curr = curr->next;
    }
    // if pos > size+1
    if(curr == NULL)
        return head;

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}


int main()
{


    Node *head = new Node(10);
    Node *node1 = new Node(11);
    Node *node2 = new Node(12);
    Node *node3 = new Node(13);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    traverseLinkedList(head);

    // insert at begin
    head = insertBegin(head, 9);
    head = insertBegin(head, 8);
    head = insertBegin(head, 7);
    head = insertBegin(head, 6);
    head = insertBegin(head, 5);
    traverseLinkedList(head);
    
    // insert at end
    // head = insertEnd(head, 15);
    insertEnd(head, 15);
    insertEnd(head, 20);
    insertEnd(head, 25);
    traverseLinkedList(head);

    // insert at position p
    insertAtPosition(head, 3, 100);
    insertAtPosition(head, 3, 200);
    insertAtPosition(head, 8, 200);
    insertAtPosition(head, 9, 100);
    insertAtPosition(head, 115, 100);
    traverseLinkedList(head);

    return 0;
}