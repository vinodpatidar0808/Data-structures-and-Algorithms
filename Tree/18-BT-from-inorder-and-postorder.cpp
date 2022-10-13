// construct binary tree from inorder and post order

#include <iostream>

#include "binaryTree.h"

using namespace std; 

node * constructTreeUtil(int inorder[], int postorder[], int s, int e)
{
    if(s > e)
        return NULL; 
    static int postInd = e;
    node *root = new node(postorder[postInd--]);
    int rootInd ;
    for(int i =s ; i <= e ; i++)
    {
        if(inorder[i] == root->val)
        {
            rootInd = i;
            break;
        }
    }

    root->right = constructTreeUtil(inorder, postorder, rootInd+1, e);
    root->left = constructTreeUtil(inorder, postorder, s, rootInd-1);
    return root;
}

node * constructTree(int inorder[], int postorder[], int n)
{
    if(n == 0) return NULL;
    return constructTreeUtil(inorder, postorder, 0, n-1);
}


int main()
{
    
    int inorder[] = {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int postorder[] = {35,30,45,75,65,55,50,20,60,90,100,80,70,40,10};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    node *root = constructTree(inorder, postorder, n);
    printTreeLineByLine(root);



    return 0;
}