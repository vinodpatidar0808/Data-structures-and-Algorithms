// desing a data structure that allows following operations efficiently 
// search, insert, delete and kth smallest
#include <iostream>

#include "bst.h"

using namespace std; 

// simple approach for kth smallest : using inorder traversal, inorder  traversal of binary search tree is always sorted(ascending)
// time comp : O(n)

void printKth(node *root, int k)
{
    static int count = 0;
    if(root == NULL)
        return ;
    printKth(root->left, k);
    count++;
    if(count == k)
    {
        cout<<root->val<<endl;
        return ;
    }
    printKth(root->right,k);

}

int main()
{
    node *root = new node(10);
    node *node1 = new node(7);
    node *node2 = new node(12);
    node *node3 = new node(5);
    node *node4 = new node(8);
    node *node5 = new node(11);
    node *node6 = new node(15);
    node *node7 = new node(3);
    node *node8 = new node(6);
    node *node9 = new node(9);
    node *node10 = new node(14);
    node *node11 = new node(16);
    node *node12 = new node(2);
    node *node13 = new node(4);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node3->right = node8;
    node4->right = node9;
    node6->left = node10;
    node6->right = node11;
    node7->left = node12;
    node7->right = node13;

    inorder(root);
    cout<<endl;
    int k = 15;
    printKth(root, k);

    return 0;
}