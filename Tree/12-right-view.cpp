#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 

void rightViewUtil(node *root, int &lastLevel, int currLevel)
{
    if(root == NULL) return;
    if(lastLevel< currLevel) 
    {
        cout<<root->val<<endl;
        lastLevel++;
    }
    rightViewUtil(root->right,lastLevel,currLevel+1);
    rightViewUtil(root->left,lastLevel,currLevel+1);

}

// time comp : O(n), space comp : O(h)
void rightView(node * root)
{
    int lastPrintedLevel = 0;
    // 1 = current level
    rightViewUtil(root,lastPrintedLevel, 1);
}

void rightViewIterative(node * root)
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
            if(i == count-1)
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
    rightView(root);
    rightViewIterative(root);
    return 0;
}