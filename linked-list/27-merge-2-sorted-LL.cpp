#include <iostream>

#include "LLtemplate.h"

using namespace std; 

Node * mergeLists(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    if(head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
        tail->next = head2;
    else
        tail->next = head1;
    return head;


}


int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    
    for(int i = 30; i > 0; i=i-3)
    {
        head1 = insertBegin(head1, i);
    }

    for(int i = 30; i > 0; i=i-2)
    {
        head2 = insertBegin(head2, i);
    }
    traverseLinkedList(head1);
    traverseLinkedList(head2);

    Node *head = mergeLists(head1, head2);
    traverseLinkedList(head);

    return 0;

}