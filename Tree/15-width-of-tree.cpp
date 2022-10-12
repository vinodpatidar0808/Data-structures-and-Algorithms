#include <iostream>
#include <queue>

#include "binaryTree.h"

using namespace std; 


int width(node *root)
{
    if(root == NULL) return 0;
    int res = 0;
    queue<node *> q;
    q.push(root);
    int count ;
    node *temp ;
    while(!q.empty())
    {
        count = q.size();
        res = max(res, count);
        for(int i = 0; i < count; i++)
        {
            temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return res;

}

int main()
{
    node *root = new node(10);
    node *node1 = new node(6);
    node *node2 = new node(4);
    node *node3 = new node(3);
    node *node4 = new node(3);
    node *node5 = new node(2);
    node *node6 = new node(2);
    node *node7 = new node(11);
    node *node8 = new node(12);
    
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node3->right = node8;

    cout<<"width of the tree is "<<width(root)<<endl;    
    return 0;
}