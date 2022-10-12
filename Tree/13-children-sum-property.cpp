//check whether sum of left node value and right node value is equal to root parent node value for each node in the tree

#include <iostream>

#include "binaryTree.h"

using namespace std; 

bool isChildrenSum(node * root)
{
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    
    int sum = 0;
    if(root->left) sum+=root->left->val;
    if(root->right) sum+=root->right->val;

    return (root->val == sum && isChildrenSum(root->left) && isChildrenSum(root->right));

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
    
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    cout<<boolalpha;
    cout<<isChildrenSum(root)<<endl;

    node *root2 = NULL;
    cout<<isChildrenSum(root2)<<endl;

    root = new node(10);
    cout<<isChildrenSum(root2)<<endl;

    return 0;
}