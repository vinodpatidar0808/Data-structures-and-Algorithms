#ifndef CIRCULARLL_H_
#define CIRCULARLL_H_

#include <iostream>

struct node{
    int data;
    node * next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};


// using do while loop
void traverse(node *head)
{
    if(head == NULL)
    {
        std::cout<<"NULL"<<std::endl;
        return;
    } 

    node *curr = head;
    do{
        std::cout<<curr->data<<" -> ";
        curr = curr->next;
    }while(curr != head);
    std::cout<<"NULL"<<std::endl;
}

node * insert(node * head, int val)
{
    node * newNode = new node(val);
    if (head == NULL)
    {
        newNode->next = newNode ;
        return newNode;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode ;
        int t = head->data;
        head->data = newNode->data;
        newNode->data = t;
    }
    return head;
}

#endif