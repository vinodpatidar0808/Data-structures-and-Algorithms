// convert binary tree to doubly linked list (in place)
#include <iostream>

#include "binaryTree.h"

using namespace std; 

// we are using inorder traversal and left most node of tree will be head of the list
// time comp : o(n), space comp : O(h)
node *treeToLL(node * root)
{
    if(root == NULL) return root;
    static node *prev = NULL;
    node *head = treeToLL(root->left);
    if(prev == NULL) 
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    
    treeToLL(root->right);
    return head;
}

void printLinkedList(node *head)
{
    if(head == NULL) return;
    node *curr = head;
    while(curr != NULL) {
        cout<<curr->val<<" <=> ";
        curr = curr->right;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *root = new node(10);
    node *node1 = new node(6);
    node *node2 = new node(4);
    node *node3 = new node(3);
    node *node4 = new node(3);
    node *node5 = new node(2);
    node *node6 = new node(2);
    node *node7 = new node(11);
    node *node8 = new node(12);
    
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node3->right = node8;

    node *head = treeToLL(root);
    printLinkedList(head);


    return 0;
}