#include <iostream>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n)
int height(node *root)
{
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right))+1;
}

// time comp : O(n^2)
bool isBalanced(node *root){
    if(root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    
    return (abs(lh - rh) <=1 && isBalanced(root->left) && isBalanced(root->right));
}

// time comp : O(n)
// every function call do 2 things checks whether subtree is balanced or not and also returns height
int balancedTree(node *root)
{
    if(root == NULL) return 0;
    int lh = balancedTree(root->left);
    if(lh == -1) return -1;
    int rh = balancedTree(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1)
        return -1;
    return max(lh, rh)+1;
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

    cout<<boolalpha;
    cout<<"Tree is balanced: "<<isBalanced(root)<<endl;
    return 0;
}