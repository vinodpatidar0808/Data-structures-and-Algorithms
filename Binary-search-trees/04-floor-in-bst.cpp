#include <iostream>
#include <vector>

#include "bst.h"

using namespace std; 

void fillInorder(node *root, vector<node*> &inorder)
{
    if(root == NULL)
        return;
    fillInorder(root->left, inorder);
    inorder.push_back(root);
    fillInorder(root->right, inorder);
}


// time comp : O(n) , space comp : O(n)
node *floorBst(node *root, int x)
{
    vector<node*> inorder ;
    fillInorder(root, inorder);

    node *floorNode = NULL;
    for(auto curr: inorder)
    {
        if(curr->val <= x)
            floorNode = curr;
        else 
            break;
    }

    return floorNode;
}


// time comp : O(h)
node *floor(node *root, int x)
{
    node *floorNode = NULL;
    while(root)
    {
        if(root->val == x)
            return root;
        else if(root->val > x)
            root = root->left;
        else
        {
            floorNode = root;
            root = root->right;
        }
    }
    return floorNode;
}

int main()
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->right = new node(8);
    root->right->left = new node(11);
    root->right->right = new node(15);   
    int x = 14;
    // node *floorNode = floorBst(root, x);
    node *floorNode = floor(root, x);
    if(floorNode)
        cout<<"floor of "<<x<<" is "<<floorNode->val<<endl;
    else 
        cout<<"no floor exist for "<<x<<endl;
    
    return 0;
}