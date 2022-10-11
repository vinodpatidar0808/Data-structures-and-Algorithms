#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n) ==> n : number of nodes
// space : O(w) ==> w : width of the tree
void levelOrder(node *root){
    if(root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    node *temp ;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
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
    levelOrder(root);
    return 0;
}