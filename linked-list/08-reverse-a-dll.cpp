#include <iostream>
#include "dllTemplate.h"

using namespace std; 

node * reverseLinkedList(node *head)
{
    if(head == NULL || head->next == NULL) return head;
    node *prevNode = NULL;  
    node *curr = head;
    while (curr != NULL)
    {
        prevNode = curr->prev;
        curr->prev = curr->next;
        curr->next = prevNode;
        curr = curr->prev;
    }
    return prevNode->prev;
}

int main()
{
    node * head = NULL;
    cout<<"enter values to create linked list, press -1 to finish..."<<endl;
    int x {0};
    while ( true)
    {
        cin>> x;
        if (x == -1) break;
        head = insertBegin(head, x);
    }
    traverseLinkedList(head);
    head = reverseLinkedList(head);
    traverseLinkedList(head);

    return 0;
}