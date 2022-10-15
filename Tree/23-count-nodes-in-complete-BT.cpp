// complete binary tree: if tree is completely filled except last level, and last level is filled from left to right.
// perfect binary tree: all leaf nodes are at same level i.e left and right height at each node is equal

#include <iostream>
#include <math.h>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n)
int countNodes(node * root)
{
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// time comp : O(log(n)*log(n)) 
//NOTE: nodes in a perfect binary tree of height h = (2^h-1)
int countNodes2(node *root)
{
    int lh = 0, rh = 0;
    node * curr = root;
    while(curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while(curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if(lh == rh)
    {
        return pow(2,lh)-1;
    }
    return 1 + countNodes2(root->left) + countNodes2(root->right);
}

int main()
{
    // tree is a complete binary tree
    int inorder[]  {80,40,90,20,100,50,110,10,60,30,70};
    int preorder[] {10,20,40,80,90,50,100,110,30,60,70};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);    
    printTreeLineByLine(root);
    cout<<"number of nodes in tree is : "<<countNodes(root)<<endl;
    cout<<"number of nodes in tree is : "<<countNodes2(root)<<endl;

    return 0;
}