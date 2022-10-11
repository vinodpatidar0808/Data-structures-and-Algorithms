#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n) ==> n : number of nodes
// space : O(w) ==> w : width of the tree
void levelOrderLineByLine(node *root){
    if(root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    node *temp ;
    
    while (q.size() > 1){
        temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}

// time comp : O(n) : each node goes into queue once and come out once
// space : O(w) 
void levelOrderL2L(node *root)
{
    if(root == NULL)
        return ;
    queue<node *> q;
    q.push(root);
    int count ;
    node *temp ;
    while(!q.empty())
    {
        count = q.size();
        for(int i=0;i<count;i++)
        {
            temp = q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout<<endl;
    }
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
    levelOrderLineByLine(root);
    levelOrderL2L(root);
    return 0;
}