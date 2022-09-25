#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"



using namespace std; 

// time comp : O(n)
Node *reverseLinkedList(Node *head){
    Node *prevNode = NULL;
    Node *nextNode = NULL;
    Node *curr = head;
    while (curr!= NULL){
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}

// recursive function to reverse the linked list
// here we reverse last n-1 nodes and then link with remaining nodes
Node *reverseLinkedListRec(Node *head){
    if (head==NULL || head->next == NULL) return head;

    Node *rem_head = reverseLinkedListRec(head->next);
    Node *rem_tail = head->next;
    rem_tail->next = head;
    head->next = NULL;
    return rem_head;

}


// recursive reverse : reverse first n-1 nodes then link with remaining nodes

Node *reverseLinkedListRec2(Node *curr, Node *prevNode){
    if(curr==NULL)
        return prevNode;
    Node *nextNode = curr->next;
    curr->next = prevNode;
    return reverseLinkedListRec2(nextNode, curr);
}



int main()
{
    int n ;
    cout<<"Enter size of the linked list to generate automatically"<<endl;
    cin>>n;
    Node *head = NULL;
    srand(time(0));
    while(n>0)
    {
        // getRandom(minvalue, maxValue): change this min and max value to get random in different range.
        // cout<<getRandom(1,200)<<" ";

        head = insertBegin(head, getRandom(1,200));
        n--;
    }
    traverseLinkedList(head);

    // iterative reversal 
    head = reverseLinkedList(head);
    traverseLinkedList(head);

    // recursive reversal 
    head = reverseLinkedListRec(head);
    traverseLinkedList(head);

    head = reverseLinkedListRec2(head, NULL);
    traverseLinkedList(head);

    cout<<endl;
    return 0;
}