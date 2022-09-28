#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std;


// using mergeSort to sort the list

// merge function to merge to sortd list
Node *merge(Node *head1, Node *head2)
{
    Node *head , *tail;
    if(head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2; 
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if(head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;
    return head;
}

// time comp: O(nlog(n))
Node *mergeSort(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;
    while(fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    Node *headLeft = mergeSort(head);
    Node *headRight = mergeSort(fast);

    head = merge(headLeft, headRight);
    return head;
}


Node *mergeSort2(Node *head, vector<Node *> &v, int l, int r)
{
    if(head == NULL || head->next == NULL)
        return head;
    int mid = l + (r-l)/2;

    Node *right = v[mid]->next;
    v[mid]->next = NULL;
    Node *leftHead = mergeSort2(head, v, l, mid);
    Node *rightHead = mergeSort2(right, v, mid+1, r);

    return merge(leftHead, rightHead);

}

// we can store nodes in a array/vector to find middle efficiently
Node *sortList(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    vector<Node*> v;
    for(Node * curr = head; curr != NULL; curr = curr->next)
    {
        v.push_back(curr);
    }

    return mergeSort2(head, v, 0, v.size()-1);
    
}

using namespace std; 

int main()
{
    cout<<"enter size of linked list"<<endl;
    int n ;
    cin>>n;
    Node *head = NULL;
    srand(time(0));
    while(n>0)
    {
        head = insertBegin(head, getRandom(1,500));
        n--;
    }    
    traverseLinkedList(head);
    head = mergeSort(head);
    head = sortList(head);
    traverseLinkedList(head);



    return 0;
}