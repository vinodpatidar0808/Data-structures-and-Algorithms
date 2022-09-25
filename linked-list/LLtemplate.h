#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <iostream>


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

    std::cout<<"Linked list:  ";
    Node *curr = head;
    while(curr!=NULL)
    {
        std::cout<<curr->data<<"->";
        curr = curr->next;
    }
    std::cout<<"NULL"<<std::endl;
}


Node *insertBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

#endif