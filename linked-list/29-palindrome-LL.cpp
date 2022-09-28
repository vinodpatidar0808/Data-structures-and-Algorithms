// check if linked list is a palindrome or not

#include <iostream>
#include <stack>

#include "LLtemplate.h"


using namespace std; 


// time comp; O(n), space comp; O(n)
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    stack<int> s;
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        s.push(curr->data);
    }
    for(Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.top() != curr->data)
            return false;
        s.pop();
    }
    return true;  
}

Node *reverse(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *prevNode = NULL;
    Node *nextNode = NULL;
    Node *curr = head;
    while(curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}



bool isPalindrome2(Node *head)
{
    if(head==NULL || head->next==NULL)
        return true;

    Node *first = head;
    Node * second = head->next;
    while(second!=NULL && second->next!= NULL)
    {
        first = first->next;
        second = second->next->next;
    }
    second = first->next;
    first->next = NULL;
    // if(second->data != head->data)
    //     return 0;
    Node *newHead = reverse(second);

    Node *curr = newHead;
    Node *temp = head;
    while(curr!=NULL)
    {
        if(curr->data == temp->data)
        {
            curr=curr->next;
            temp = temp->next;
        }
        else
            return false;
    }
    // restoring the original list
    Node *tail = reverse(newHead);
    first->next = tail;
    return true;
}



int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,0};
    // int arr[] = {0,1,2,3,4,5,6,7,7,6,5,4,3,2};
    // int arr[] = {0,1,2,3,4,5,6,8,9,9,8,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *head = NULL;
    while(n>0)
    {
        head = insertBegin(head, arr[n-1]);
        n--;
    }

    traverseLinkedList(head);
    cout<<boolalpha;

    cout<<"linked list is palindrome: "<<isPalindrome(head)<<endl;
    cout<<"linked list is palindrome: "<<isPalindrome2(head)<<endl;
    traverseLinkedList(head);
    return 0;
}