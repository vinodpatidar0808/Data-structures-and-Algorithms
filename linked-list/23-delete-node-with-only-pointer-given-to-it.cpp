// delete a node with only pointer given to it, assume node to delete is not last node

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "LLtemplate.h"
#include "generateRandom.h"


using namespace std; 

void deleteNode(Node *node) {
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

int main()
{
    cout<< "enter size of linked list, size must be great than 1"<< endl;
    int n;
    cin>>n;
    Node* arr[n];
    Node *head = NULL;
    int i = n;
    while(i > 0)
    {
        head = insertBegin(head, getRandom(1,500));
        arr[--i] = head;
    }
    traverseLinkedList(head);

    int rand = getRandom(0,n-1);
    deleteNode(arr[rand]);
    traverseLinkedList(head);
    return 0;
}