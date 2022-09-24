#include <iostream>
#include <string>

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

// search and return position (not index), if not present return -1;
// time comp: O(n)
int search(Node *head, int val)
{
    if(head == NULL)
        return -1;
    int pos =1 ;
    Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->data == val)
            return pos;
        curr = curr->next;
        pos++;
    }
    return -1;
}

int searchRec(Node *head, int val)
{
    if(head == NULL)
        return -1;
    if(head->data == val)
        return 1;
    else
    {
        int res = searchRec(head->next,val);
        if(res== -1)
            return -1;
        else
            return res + 1;
    }
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

    int n ;
    cout<<"enter value to search: "<<endl;
    cin>>n;

    // int pos = search(head, n);
    int pos = searchRec(head, n);
    if(pos == -1)
    {
        cout<<n<<" not present in LL"<<endl;
    }
    else{
        cout<<n<<" found at position "<<pos<<endl; 
    }

    
    return 0;
}