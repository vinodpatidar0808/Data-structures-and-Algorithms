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
    cout<<"Linked list is :"<<endl;
    Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

Node *insertBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

// deleting first node;
Node *deleteFirstNode(Node *head)
{
    if(head == NULL)
        return NULL;
    Node *newHead = head->next;
    delete head;
    return newHead;
}

Node *deleteLastNode(Node *head)
{
    if(head == NULL) 
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node * curr = head;
    while(curr->next!=NULL && curr->next->next !=NULL)
        curr = curr->next;
    delete curr->next;
    curr->next = NULL;
    return head;
}


int main()
{   
    cout<<"enter values to create a linked list, enter -1 to finish"<<endl;
    int val {0};
    Node *head =NULL;
    while(val != -1)
    {
        cin>>val;
        if(val == -1)
            break;
        head = insertBegin(head, val);
    }    
    traverseLinkedList(head);

    // delete first node
    head = deleteFirstNode(head);
    head = deleteFirstNode(head);
    head = deleteFirstNode(head);
    
    traverseLinkedList(head);

    // delete last node 
    head = deleteLastNode(head);
    head = deleteLastNode(head);
    head = deleteLastNode(head);
    traverseLinkedList(head);

    return 0;
}