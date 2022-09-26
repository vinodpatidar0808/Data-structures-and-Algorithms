
#include <iostream>
#include "CLLtemplate.h"


using namespace std; 

// insert at beginning of the circular linked list
// time comp : O(n) 
node * insertBegin(node * head, int val)
{
    node * newNode = new node(val);
    if(head == NULL)
    {
        newNode->next = newNode ;
    }
    else
    {
        node *curr = head;
        while(curr->next!= head)
        {
            curr = curr->next;
        }
        curr->next = newNode ;
        newNode->next = head;
    }
    return newNode;
}

// insert at beginning 
// time comp : O(1) 
node * insertBegin2(node * head, int val)
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


// insert node at the end
// time comp : O(n) 

node * insertEnd(node * head, int val)
{
    node * newNode = new node(val);
    if (head == NULL){
        newNode->next = newNode ;
        return newNode;
    }
    else{
        node *curr = head;
        while(curr->next!= head)
        {
            curr = curr->next;
        }
        curr->next = newNode ;
        newNode->next = head;
        return head;
    }
}

// insert at the end 
// time comp : O(1)
node *insertEnd2(node * head, int val)
{
    node * newNode = new node(val);
    if (head == NULL){
        newNode->next = newNode ;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode ;
    int t = head->data;
    head->data = newNode->data;
    newNode->data = t;
    head = head->next;
    return head;
}

int main()
{
    // /*
    node * head = new node(10);
    node * node1 = new node(20);
    node * node2 = new node(30);
    node * node3 = new node(40);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = head;
    // */
    // node * head = NULL;
    traverse(head);
    
    // insert node at beginning of list
    head = insertBegin(head, 100);
    head = insertBegin(head, 200);
    traverse(head);

    head = insertBegin2(head, 500);
    head = insertBegin2(head, 600);
    traverse(head);

    head = insertEnd(head, 555);
    head = insertEnd(head, 666);

    head = insertEnd2(head, 1000);
    head = insertEnd2(head, 1500);
    traverse(head);

    return 0;
}