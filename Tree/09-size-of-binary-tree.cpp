#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n) ==> n : number of nodes
// space : O(h) ==> h : height of the tree
int size(node * root)
{
    if(root == NULL) return 0;

    return 1 + size(root->left) + size(root->right);
}

// iterate 
int getSize(node * root)
{
    if(root == NULL) return 0;
    int size = 0;
    queue<node *> q;
    q.push(root);
    node *temp ;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        size++;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    
    return size;
}

int main()
{
    node *root = new node(6);
    node *node1 = new node(8);
    node *node2 = new node(7);
    node *node3 = new node(4);
    node *node4 = new node(3);
    node *node5 = new node(1);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    cout<<"size of tree is: "<<size(root)<<endl;
    cout<<"size of tree is: "<<getSize(root)<<endl;
    return 0;
}