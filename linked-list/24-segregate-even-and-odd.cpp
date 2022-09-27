// given a linked list of even and odd numbers, segregate list in even and odd order, 
// relative order of elements must be preserved

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"


using namespace std; 

// keeping evens first
// time comp : O(n)

Node *evenOdd(Node *head)
{
    Node *evenHead {NULL}, *evenTail {NULL};
    Node *oddHead {NULL}, *oddTail {NULL};

    Node *curr = head;
    while(curr != NULL)
    {
        if(curr->data % 2==0)
        {
            if(evenHead != NULL)
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            else
            {
                evenHead = curr;
                evenTail = curr;
            }
        }
        else
        {
            if(oddHead != NULL)
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
            else
            {
                oddHead = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }
    if(evenHead == NULL || oddHead == NULL )
        return head;
    evenTail->next = oddHead;
    oddTail->next = NULL;
    return evenHead;
}

int main()
{
    cout<<"enter size of list"<<endl;
    int n;
    cin>>n;
    srand(time(0));
    Node *head = NULL;
    while(n>0)
    {  
        head = insertBegin(head, getRandom(1,500));
        
        // to generate only even list        
        // head = insertBegin(head, getRandomEven(1,500));

        // to generate odd list
        // head = insertBegin(head, getRandomOdd(1,500));
        n--;
    }    
    traverseLinkedList(head); 

    head = evenOdd(head);
    traverseLinkedList(head);


    return 0;
}