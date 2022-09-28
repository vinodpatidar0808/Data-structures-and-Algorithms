#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <vector>

#include "generateRandom.h"

using namespace std;

struct node {
    int data;
    node *next;
    node *random;
    node(int d) {
        data = d;
        next = NULL;
        random = NULL;
    }
};

node *insertBegin(node *head, int val)
{
    node *newNode = new node(val);
    if(head == NULL)
        return newNode;
    newNode->next = head;
    return newNode;
}
void traverseList(node *head){
    node *curr = head;
    cout<<"List:   ";
    while(curr!= NULL) {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
    cout<<"Random: ";
    curr = head;
    while(curr!= NULL) {
        if(curr->random == NULL)
            cout<<"NULL"<<" ";
        else
            cout<<curr->random->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


// time comp : O(n) , space O(n) 
// requires 2 traversals
node *cloneList(node *head)
{

    // map contains node as key, and index as value
    unordered_map<node*, int> m;
    vector<node*> v;

    node *cloneHead = NULL;
    node *cloneTail = NULL;
    int i=0;
    node *curr = head;
    while(curr!= NULL) {
        if(cloneHead != NULL)
        {
            cloneTail ->next = new node(curr->data);
            cloneTail = cloneTail->next;
        }
        else{
            cloneHead = new node(curr->data);
            cloneTail = cloneHead;
        }
        v.push_back(cloneTail);
        m.insert({curr, i});
        curr = curr->next;
        i++;
    }

    curr = head;
    int randomInd ;
    cloneTail = cloneHead;
    while(curr!= NULL) {
        if(curr->random != NULL)
        {
            randomInd = m[curr->random];
            cloneTail->random = v[randomInd];
        }
        curr = curr->next;
        cloneTail = cloneTail->next;
    }
   
   return cloneHead;
    
}

// time comp : O(n), space comp : O(1)

node *cloneLL(node *head)
{
    node *curr = head;
    node *nextNode = NULL;

    // inserting copy of each node
    while(curr!= NULL) {
        nextNode = curr->next;
        curr->next = new node(curr->data);
        curr->next->next = nextNode;
        curr = nextNode;
    }

    // make random connection
    for(node *curr = head; curr!= NULL; curr = curr->next->next)
    {
        curr->next->random = curr->random != NULL ? curr->random->next : NULL;
    }

    // get original and cloned list by separating alternate nodes
    node *cloneHead = NULL;
    node *cloneTail = NULL;
    curr = head;
    while(curr!= NULL) {
        nextNode = curr->next->next;
        if(cloneHead != NULL)
        {
            cloneTail->next = curr->next;
            cloneTail = cloneTail->next;
        }
        else
        {
            cloneHead = curr->next;
            cloneTail = cloneHead;
        }
        curr = nextNode;
    }
    return cloneHead;

}

using namespace std; 

int main()
{
    int n ;
    cout<<"enter size of linked list"<<endl;
    cin>>n;
    node *head = NULL;
    node* arr[n] ;
    srand(time(0));
    int i= n;
    while(i>0)
    {
        head = insertBegin(head, getRandom(1,500));
        arr[i-1] = head;
        i--;
    }

    // make random connection 
    for(i =0; i<n; i++)
    {
        // maxValue greater than n: to create some random connections as NULL also
        int rand = getRandom(0, n+n/2);

        while(rand == i)
        {
            rand = getRandom(0, n);
        }
        if(rand < n)
            arr[i]->random = arr[rand];
    }

    traverseList(head);

    // node *cloneHead = cloneList(head);
    // traverseList(cloneHead);

    node *clone = cloneLL(head);
    traverseList(clone);
    return 0;
}