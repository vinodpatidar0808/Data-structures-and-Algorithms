#include <iostream>
#include <cstdlib>
#include <time.h>

#include "CLLtemplate.h"
#include "generateRandom.h"

using namespace std; 


// delete head of the circular linked list
// time comp : O(n)
node * deleteHead(node * head)
{
    if(head == NULL)
        return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }

    node * curr = head;
    while(curr->next!= head)
    {
        curr = curr->next;
    }

    node *temp = head;
    curr->next = head->next;
    delete(temp);
    return curr->next;
}

// delete head 
// time comp : O(1)

node * deleteHead2(node * head)
{
    if(head == NULL)
        return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    node *temp = head->next;
    head->next = head->next->next;
    delete(temp);
    return head;
}



int main()
{
    
    int n ;
    cout<< "Enter size of linked list to create automatically"<< endl;
    cin>>n;
    node *head = NULL;
    srand(time(0));
    while(n>0)
    {
        head = insert(head, getRandom(1,200));
        n--;
    }
    traverse(head);

    // head = deleteHead(head);
    // head = deleteHead(head);
    // head = deleteHead(head);

    head = deleteHead2(head);
    head = deleteHead2(head);
    head = deleteHead2(head);
    traverse(head);

    return 0;
}

