#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>

struct node{
    int val;
    node *left;
    node *right;
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

void inorder(node *root)
{
    if(root == NULL)
        return ;
    inorder(root->left);
    std::cout<<root->val<< " ";
    inorder(root->right);
}


#endif