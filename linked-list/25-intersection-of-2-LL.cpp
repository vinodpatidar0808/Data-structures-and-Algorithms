#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unordered_set>
#include <math.h>

#include "LLtemplate.h"
#include "generateRandom.h"

using namespace std; 

// time comp : O(n+m) , space comp : O(max(n,m))
void intersection(Node *head1, Node *head2) {
    unordered_set<Node*> s;

    Node *curr = head1;
    while(curr != NULL){
        s.insert(curr);
        curr = curr->next;
    }
    curr = head2;
    while(curr!= NULL){
        if(s.find(curr) != s.end()){
            cout<<"intersection node value "<<curr->data<<endl;
            return;
        }
        curr = curr->next;
    }
    cout<<"linked lists do not intersect"<<endl;
}

// time comp : O(n) 
// here we compute length of both the lists
// traverse the bigger list abs(len1 - len2) time
// traverse both list together until we reach a common node
void intersectionNode(Node * head1, Node *head2)
{
    int len1 = 0;
    int len2 = 0;
    Node *curr1 {head1}, *curr2 {head2};
    while(curr1 !=NULL)
    {
        len1++;
        curr1 = curr1->next;
    }
    while(curr2 !=NULL)
    {
        len2++;
        curr2 = curr2->next;
    }

    Node *temp = NULL;
    int diff = abs(len1 - len2);
    if(len2 > len1)
    {
        temp = head1;
        head1 = head2;
        head2 = temp;
    }
    curr1 = head1;
    int count = 0;
    while(count<diff)
    {
        curr1 = curr1->next;
        count++;
    }
    curr2 = head2;
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1 == curr2)
        {
            cout<<"intersection node value "<< curr1->data<<endl;
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    cout<<"linked list do not intersect"<< endl;

}


int main()
{
    cout<<"enter size of 2 lists"<<endl;
    int n, m;
    cin >> n >> m;
    // arrays to store nodes to make random connection b/w 2 lists
    Node* arr[n];
    Node* arr2[m];
    int i = n;
    srand(time(0)); 
    Node *head1 = NULL;
    Node *head2 = NULL;
    while(i>0)
    {
        head1 = insertBegin(head1, getRandom(1,200));
        arr[--i] = head1;
    }
    i = m;
    while(i>0)
    {
        head2 = insertBegin(head2, getRandom(1,200));
        arr2[--i] = head2;
    }
    // traverseLinkedList(head1);
    // traverseLinkedList(head2);

    int rand = getRandom(0, n);
    arr2[m-1]->next = arr[rand];

    traverseLinkedList(head1);
    traverseLinkedList(head2);

    intersection(head1, head2);
    intersectionNode(head1, head2);



    return 0;
}