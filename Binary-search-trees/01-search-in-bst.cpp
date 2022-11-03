#include <iostream>

#include "bst.h"

using namespace std; 


// time comp : O(h), aux space : O(h)
bool searchBst(node *root, int key)
{
    if(root == NULL) return false;
    if(root->val == key) return true;
    else if( root->val < key)
        return searchBst(root->right, key);
    else
        return searchBst(root->left, key);
}

// Iterative 
// time comp : O(h)
bool searchBstIterative(node *root, int key)
{
    while(root)
    {
        if(root->val == key)
            return true;
        else if(root->val > key)
            root = root->left;
        else 
            root = root->right;
    }
    return false;
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

    printTreeLineByLine(root);

    // value to search
    int x = 12;
    // bool res = searchBst(root, x);
    bool res = searchBstIterative(root, x);
    if(res)
        cout<<x<<" is present in the tree"<<endl;
    else
        cout<<x<<" is not present in the tree"<<endl;

    return 0;
}