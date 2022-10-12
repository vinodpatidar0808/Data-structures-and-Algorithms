#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 

void leftViewUtil(node *root, int &lastLevel, int currLevel)
{
    if(root == NULL) return;
    if(lastLevel< currLevel) 
    {
        cout<<root->val<<endl;
        lastLevel++;
    }
    leftViewUtil(root->left,lastLevel,currLevel+1);
    leftViewUtil(root->right,lastLevel,currLevel+1);

}

// time comp : O(n), space comp : O(h)
void leftView(node * root)
{
    int lastPrintedLevel = 0;
    // 1 = current level
    leftViewUtil(root,lastPrintedLevel, 1);
}

void leftViewIterative(node * root)
{
    if(root == NULL) return;
    queue<node *> q;
    q.push(root);
    int count ;
    node * temp;
    while(!q.empty())
    {
        count = q.size();
        for(int i=0;i<count;i++)
        {
            temp = q.front();
            q.pop();
            if(i == 0)
                cout<<temp->val<<endl;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = new node(8);
    node *node1 = new node(7);
    node *node2 = new node(6);
    node *node3 = new node(4);
    node *node4 = new node(3);
    node *node5 = new node(1);
    node *node6 = new node(9);
    node *node7 = new node(10);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;
    node4->left = node5;
    node3->left = node6;
    node5->right = node7;
    leftView(root);
    leftViewIterative(root);
    return 0;
}