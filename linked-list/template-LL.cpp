#include <iostream>

using namespace std; 

struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

void traverseLinkedList(Node *head)
{

    cout<<"Linked list:  ";
    Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{   
    
    return 0;
}