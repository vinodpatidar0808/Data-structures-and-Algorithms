// delete nodes in doubly linked list
#include <iostream>

using namespace std; 


struct node {
    int data;
    node* next;
    node * prev;
    node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void traverseLinkedList(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data <<" <==> ";
        curr = curr->next;
    }

    cout <<"NULL"<< endl;
}

node *insertBegin(node *head, int x)
{
    node *newnode = new node(x);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    return newnode;
}

// delete head of linked list
// time comp : O(1)
node *deleteHead(node *head)
{
    if (head == NULL) 
        return NULL;

    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    node *temp = head;
    head = head->next;
    delete temp;
    head->prev = NULL;
    return head;
}


// delete last node of linked list
// time comp : O(n)
node *deleteLast(node *head)
{
    if (head == NULL)
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while(curr->next !=NULL)
    {
        curr = curr->next;
    } 
    curr->prev->next = NULL;
    delete curr;
    return head;
}


int main()
{
    cout<<"Enter values to creat linked list, press -1 to finish..."<< endl;
    node *head = NULL;
    int x {0};
    while(x != -1){
        cin>>x;
        if(x == -1) break;
        head = insertBegin(head,x);
    }
    traverseLinkedList(head);
    // head = deleteHead(head);
    // head = deleteHead(head);
    // head = deleteHead(head);
    // traverseLinkedList(head);
    
    head = deleteLast(head);
    head = deleteLast(head);
    head = deleteLast(head);
    traverseLinkedList(head);
    return 0;
}