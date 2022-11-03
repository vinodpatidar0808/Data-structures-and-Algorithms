// insert a key in binary search tree if the key is not already present

#include <iostream>

#include "bst.h"

using namespace std; 

// time comp : O(h), aux space : O(h)
node * insertInBst(node *root, int x)
{
    if(root == NULL) 
        return new node(x);
    else if(root->val < x)
        root->right = insertInBst(root->right,x);
    else if(root->val > x)
        root->left = insertInBst(root->left,x);
    return root;
}

// iterative 
// time comp : O(h)
node * insertInBstIterative(node *root, int x)
{
    node *temp = new node(x);
    node *parent = NULL, *curr = root;
    while(curr)
    {
        parent = curr ;
        if(curr->val > x)
            curr = curr->left;
        else if(curr->val < x)
            curr = curr->right;
        // x already present in the tree
        else 
            return root;
    }

    // handle empty tree
    if(parent == NULL)
        return temp;
    if(parent->val > x)
        parent->left = temp;
    else 
        parent->right = temp;
    return root;
}




int main()
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->right = new node(8);
    root->right->left = new node(11);
    root->right->right = new node(15);

    int x = 14;
    root = insertInBst(root, x);
    // root = insertInBstIterative(root, x);
    inorder(root);
    cout<<endl;
    return 0;
}