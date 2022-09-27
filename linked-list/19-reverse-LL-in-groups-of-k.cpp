// reverse linked list in groups of k, reverse last group also if it is smaller than k.

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 

// time comp : O(n)
Node *reverseK(Node * head, int k)
{
    if (head == NULL)
        return NULL;
    Node *nextNode = NULL, *prevNode = NULL, *curr = head;
    Node *currGrpFirst = NULL, *prevGrpLast = NULL;
    bool firstGroup = true;


    int count = 0;
    while(curr != NULL)
    {
        currGrpFirst = curr;
        prevNode = NULL;
        count = 0;
        while(curr != NULL && count < k)
        {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
            count++;
        }
        if(firstGroup)
        {
            head = prevNode;
            firstGroup = false;
        }
        else{
            prevGrpLast->next = prevNode;
        }
        prevGrpLast = currGrpFirst;
    }
    return head;

}

// recursive

Node *reverseKrec(Node * head, int k)
{
    Node *curr = head, *nextNode = NULL, *prevNode = NULL;
    int count = 0;
    while(curr!= NULL && count < k)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
        count++;
    }
    if(nextNode != NULL)
    {
        Node *remListHead = reverseKrec(nextNode, k);
        head->next = remListHead;
    }
    return prevNode;
    
}

int main()
{
    int n ;
    cout<<"Enter size of linked list"<<endl;
    cin>>n;
    Node *head = NULL;
    srand(time(0));
    while(n>0)
    {
        head = insertBegin(head, getRandom(1, 200));
        n--;
    }
    traverseLinkedList(head);
    cout<<"enter group size"<<endl;
    int k;
    cin>>k;

    head = reverseK(head, k);
    traverseLinkedList(head);
    
    //recursive reverse
    head = reverseKrec(head,k);
    traverseLinkedList(head);
    

    return 0;
}