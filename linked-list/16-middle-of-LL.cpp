#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 

// when number of nodes is even right middle is printed out of 2 middles
// requires 2 traversal
// time comp : O(n)
void printMiddle(Node * head)
{
    int n {0};
    Node * curr = head;
    while (curr!= NULL)
    {
        n++;
        curr = curr->next;
    }
    cout << n << endl;
    curr = head;
    for(int i=0; i<n/2 ; i++)
        curr = curr->next;
    cout<< curr->data << endl;
}

// when number of nodes is even right middle is printed out of 2 middles
// one traversal
// time comp : O(n)
void middle(Node * head)
{
    Node *slow = head;
    Node *fast = head;
    
    while(fast!=NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

int main()
{

    int n ;
    cout<<"enter size of linked list to generate automatically"<<endl;
    cin>>n;
    Node *head = NULL;
    srand(time(0));
    while(n>0)    
    {
        head = insertBegin(head, getRandom(1,200));
        n--;
    }
    traverseLinkedList(head);
    // print middle node value
    printMiddle(head);
    middle(head);
    return 0;
}