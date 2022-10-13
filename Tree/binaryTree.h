#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <queue>

struct node {
    int val;
    node *left ;
    node *right ;
    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};

void printTreeLineByLine(node *root)
{
    if(root == NULL)
    {
        std::cout<<"NULL"<<std::endl;
        return;
    }
    std::queue<node *> q;
    q.push(root);
    int count ;
    node *temp;
    while(!q.empty()) {
        count = q.size();
        for(int i = 0; i < count; i++)
        {
            temp = q.front();
            q.pop();
            std::cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        std::cout<<std::endl;
    }
    
}

node *constructTree(int inorder[], int preorder[], int s, int e)
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

    root->left = constructTree(inorder, preorder, s, rootInd-1);
    root->right = constructTree(inorder, preorder, rootInd+1, e);
    return root;
}


#endif