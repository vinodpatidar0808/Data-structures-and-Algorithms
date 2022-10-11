#include <iostream>
#include <queue>
#include <algorithm>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n) ==> n : number of nodes
// space : O(h) ==> h : height of the tree
int maxInTree(node * root)
{
    if(root == NULL) return INT_MIN;

    return max({root->val, maxInTree(root->left), maxInTree(root->right)});
}

// iterate 
int getMax(node * root)
{
    if(root == NULL) return INT_MIN;
    queue<node *> q;
    q.push(root);
    node *temp ;
    int res = INT_MIN;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        res = max(res, temp->val);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    
    return res;
}

int main()
{
    node *root = new node(6);
    node *node1 = new node(8);
    node *node2 = new node(7);
    node *node3 = new node(4);
    node *node4 = new node(3);
    node *node5 = new node(1);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    cout<<"maximum in tree is: "<<maxInTree(root)<<endl;
    cout<<"maximum in tree is: "<<getMax(root)<<endl;
    return 0;
}