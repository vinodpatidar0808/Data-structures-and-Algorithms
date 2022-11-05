// given a binary tree in which 2 nodes are swapped, fix this tree to make it binary search tree

#include <iostream>
#include "bst.h"

using namespace std; 

// based on the previous problem 
void fixBstUtil(node *root, node *&first, node *&second)
{
    if(root == NULL) return;
    static node *prev = NULL;
    fixBstUtil(root->left, first, second);
    if(prev && root->val < prev->val)
    {
        if(first == NULL)
            first = prev;
        second = root;
        // cout<<"first = "<<first->val<<endl;
        // cout<<"second = "<<second->val<<endl;
    }
    prev = root;
    fixBstUtil(root->right,first, second);
}

// time comp : O(n)
void fixBst(node *root)
{
    node *first=NULL, *second=NULL;
    fixBstUtil(root, first, second);
    if(first && second)
    {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}


int main()
{
    // int inOrder[] {2,3,4,5,6,7,8,9,10,11,12,14,15,16};
    // int preOrder[] {10,7,5,3,2,4,6,8,9,12,11,15,14,16};

    int inOrder[] {2,3,4,15,6,7,8,9,10,11,12,14,5,16};
    int preOrder[] {10,7,15,3,2,4,6,8,9,12,11,5,14,16};

    int n = sizeof(inOrder) /sizeof(inOrder[0]);
    node *root = constructTree(inOrder, preOrder, 0, n-1);
    cout<<"inorder before fixing: "<<" ";
    inorder(root);
    cout<<endl;
    fixBst(root);
    cout<<"inorder after fixing:  "<<" ";
    inorder(root);
    cout<<endl;
    return 0;
}