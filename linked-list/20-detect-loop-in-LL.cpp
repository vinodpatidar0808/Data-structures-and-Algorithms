// check whethe there is a loop in linked list or not

#include <iostream>
#include <unordered_set>

using namespace std; 

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};


// check loop
// time comp : O(n), space comp : O(n)

void checkLoop(Node* head)
{
    unordered_set<Node*> s;
    Node* curr  = head;
    while(curr != NULL) {
        if(s.find(curr) != s.end())
        {
            cout<<"list contains loop "<<endl;
            return;
        }
        s.insert(curr);
        curr = curr->next;
    }
    cout<<"no loop in list "<<endl;
}

// using floyd cycle detection
// time comp : O(n)

void detectCycle(Node* head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            cout<<"list contains loop "<<endl;
            return;
        }
    }
    cout<<"no loop in list "<<endl;
}



int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);
    Node *node5 = new Node(6);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    // creating loop
    node5->next  = node3;

    checkLoop(head);
    detectCycle(head);

    return 0;
}