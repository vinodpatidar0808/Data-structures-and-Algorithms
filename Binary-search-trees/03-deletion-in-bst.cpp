#include <iostream>

#include "bst.h"

using namespace std; 


// closest greater (successor in inorder traversal) leftmost leaf of right subtree
node *getSuccessor(node *curr)
{
    // curr = curr->right;
    while(curr!=NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node *deleteNode(node *root, int x)
{
    if(root == NULL)
        return root;
    if(root->val > x)
        root->left = deleteNode(root->left, x);
    else if(root->val < x)
        root->right = deleteNode(root->right, x);
    else
    {
        if(root->left == NULL)
        {
            node *temp = root->right;
            delete root ;
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            delete root ;
            return temp;
        }
        else{
            node *successor = getSuccessor(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }
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

    int x = 10;
    inorder(root);
    cout<<endl;
    root = deleteNode(root, x);
    inorder(root);
    return 0;
}