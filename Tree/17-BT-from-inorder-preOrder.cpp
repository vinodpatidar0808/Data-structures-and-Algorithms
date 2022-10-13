// construct a binary tree from inorder traversal and preorder traversal

#include <iostream>

#include "binaryTree.h"

using namespace std; 



node *constructTreeUtil(int inorder[], int preorder[], int s, int e)
{
    if(s > e)
        return NULL;
    static int preInd = 0;
    node *root =  new node(preorder[preInd++]);
    int rootInd ;
    for(int i= s;i<=e;i++)
    {
        if(inorder[i] == root->val)
        {
            rootInd = i ;
            break;
        }
    }

    root->left = constructTreeUtil(inorder, preorder, s, rootInd-1);
    root->right = constructTreeUtil(inorder, preorder, rootInd+1, e);
    return root;
}

node *constructTree(int inorder[], int preorder[], int n)
{
    if(n == 0) return NULL;
    return constructTreeUtil(inorder, preorder, 0, n-1);
}

int main()
{

    int inorder[] = {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] = {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    node * root = constructTree(inorder, preorder, n);
    printTreeLineByLine(root); 
    return 0;
}