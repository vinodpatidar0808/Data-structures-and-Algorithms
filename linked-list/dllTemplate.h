#ifndef MYFILE_H_
#define MYFILE_H_

#include <iostream>

struct node {
    int data;
    node* next;
    node * prev;
    node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void traverseLinkedList(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data <<" <==> ";
        curr = curr->next;
    }

    std::cout <<"NULL"<< std::endl;
}

node *insertBegin(node *head, int x)
{
    node *newnode = new node(x);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    return newnode;
}

#endif