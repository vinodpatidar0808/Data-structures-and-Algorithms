// check if linked list contains loop, if yes remove loop from list

#include <iostream>

#include "LLtemplate.h"

using namespace std; 


void detectAndRemoveLoop(Node* head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            break;
    }
    if(slow != fast)
    {
        cout<<"No loop found"<<endl;
        return;
    }
    slow = head ;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    cout<<"Loop removed"<<endl;
}


int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);
    Node *node5 = new Node(6);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // creating loop
    // node5->next  = node3;
    
    detectAndRemoveLoop(head);
    traverseLinkedList(head);

    return 0;
}