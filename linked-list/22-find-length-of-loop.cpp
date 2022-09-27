#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 


int loopLength(Node *head)
{
    int len = 0;
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(slow != fast)
        return len;
    
    do{
        len++;
        fast = fast->next;
    }while(fast != slow);

    return len;
}


int main()
{

    int n ;
    cout<<"enter size of linked list"<<endl;
    cin>>n;
    Node* arr[n];
    Node *head = NULL;
    int i =n;
    srand(time(0));
    while(i>0)
    {
        head = insertBegin(head, getRandom(1,200));
        arr[--i] = head;
    }    
    traverseLinkedList(head);
    // create loop
    int rand = getRandom(0,n);
    // cout<<"random is "<<rand<<" expected length "<< n-rand<<endl;
    arr[n-1]->next = arr[rand];

    cout<<"Length of loop is :"<<loopLength(head)<<endl;
    return 0;
}