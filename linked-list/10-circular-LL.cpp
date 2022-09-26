#include <iostream>

using namespace std; 

struct node{
    int data;
    node * next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};


// using do while loop
void traverse(node *head)
{
    if(head == NULL)
    {
        cout<<"NULL"<<endl;
        return;
    } 

    node *curr = head;
    do{
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }while(curr != head);
    cout<<"NULL"<<endl;
}

int main()
{
    node * head = new node(10);
    node *node1 = new node(20);
    node *node2 = new node(30);
    node *node3 = new node(40);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = head;

    // traverse  linked list    
    traverse(head);
    return 0;
}