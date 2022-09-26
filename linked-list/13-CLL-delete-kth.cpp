#include <iostream>
#include <cstdlib>
#include <time.h>

#include "generateRandom.h"
#include "CLLtemplate.h"


using namespace std; 

node * deleteHead(node * head)
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

node *deleteKth(node * head, int k)
{
    if (head == NULL)
        return NULL;
    if(k == 1)
    {
        return deleteHead(head);
    }
    node *curr = head;
    for(int i = 0; i < k-2; i++)
        curr = curr->next;
    // assuming k < number of nodes
    node *temp = curr->next;
    curr->next = temp->next;
    delete(temp);
    return head;
}

int main()
{
    int n;
    cout<<"enter size of linked list: "<<endl;
    cin>>n;    
    node * head = NULL;
    srand(time(0));
    while(n>0)
    {
        head = insert(head, getRandom(1,200));
        n--;
    }
    traverse(head);
    int k ;
    cout<<"enter node position to delete (k < number of nodes):"<<endl;
    cin>>k;
    deleteKth(head, k);
    traverse(head);
    return 0;
}