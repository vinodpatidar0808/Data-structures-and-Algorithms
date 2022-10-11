// print nodes at k distance from root node

#include <iostream>

#include "binaryTree.h"

using namespace std; 


// time comp : O(n) ==> n : number of nodes
// space : O(h) ==> h : height of the tree
void printAtK(node * root, int k)
{
    if(root == NULL) return;
    if(k == 0)
    {
        cout<<root->val<< " ";
    }
    else{
        printAtK(root->left, k-1);
        printAtK(root->right, k-1);
    }

}

int main()
{
    node *root = new node(1);
    node *node1 = new node(2);
    node *node2 = new node(3);
    node *node3 = new node(4);
    node *node4 = new node(5);
    node *node5 = new node(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    
    int k = 2;
    cout<<"nodes at distance "<<k<<" from root "<<endl;
    printAtK(root, k);
    return 0;
}