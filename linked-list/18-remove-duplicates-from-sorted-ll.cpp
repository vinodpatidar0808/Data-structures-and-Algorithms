#include <iostream>

#include "LLtemplate.h"

using namespace std; 

void removeDuplicates(Node *head)
{
    if (head == NULL)
        return;
    
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    

}

int main()
{

    // to create  linked list
    // int arr[] = {1,1,1,1,2,2,3,4,5,6,6,7,8,8,8,8,9,10,10,10,10,10,10,10,10,10,};
    // int arr[] = {1,1,1,1,1,1,1,1};
    // int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int arr[] = {};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *head = NULL;

    while(n>0)
    {
        head = insertBegin(head, arr[n-1]);
        n--;
    }    
    traverseLinkedList(head);

    removeDuplicates(head);
    traverseLinkedList(head);
    return 0;
}