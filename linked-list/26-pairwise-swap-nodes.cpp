#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 


// swapping data of pairs
// time comp : O(n)
Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node * curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        curr = curr->next->next ;
    }
    return head ;
}

// swapping links
// time comp : O(n)

Node *linkWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node * curr = head->next->next;
    Node *prevNode = head;
    head = head->next;
    head->next = prevNode;

    Node *nextNode = NULL;
    while (curr!= NULL && curr->next!= NULL)
    {
        prevNode->next = curr->next;
        prevNode = curr;
        nextNode = curr->next->next;
        curr->next->next = curr;
        curr = nextNode;
    }
    prevNode->next = curr;
    return head;

}

int main()
{
    cout<< " enter size of linked lists..."<<endl;
    int n;
    cin>>n;
    Node *head = NULL;
    srand(time(0));
    while(n>0)
    {
        head = insertBegin(head, getRandom(1,200));
        n--;
    }    
    traverseLinkedList(head);

    head = pairWiseSwap(head);
    traverseLinkedList(head);
    head = linkWiseSwap(head);
    traverseLinkedList(head);

    return 0;
}