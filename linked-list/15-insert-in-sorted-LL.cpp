// insert node at it's correct position in sorted linked list

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"

using namespace std; 

Node *insert(Node *head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
        return newNode;
    if(val < head->data)
    {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    while(curr->next!= NULL && curr->next->data < val)
    {
        curr = curr->next;
    }
    newNode->next = curr-> next;
    curr->next = newNode;
    return head;

}

int main()
{
    int n;
    cout<<"enter size of linked list to create it automatically"<<endl;
    cin>>n;
    Node * head = NULL;
    while(n>0)
    {
        head = insertBegin(head, n);
        n--;
    }
    traverseLinkedList(head);

    cout<<"enter element to insert in linked list"<<endl;
    int k;
    cin>>k;
    head = insert(head, k);
    traverseLinkedList(head);

    return 0;
}