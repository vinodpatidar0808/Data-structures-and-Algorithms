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
node *ceilBst(node *root, int x)
{
    vector<node*> inorder ;
    fillInorder(root, inorder);

    node *ceilNode = NULL;

   int n = inorder.size();
    for(int i=n-1 ;i >= 0 ;i--)
    {
        if(inorder[i]->val >= x)
            ceilNode = inorder[i];
        else 
            break;
    }

    return ceilNode;
}


// time comp : O(h)
node *ceil(node *root, int x)
{
    node *ceilNode = NULL;
    while(root)
    {
        if(root->val == x)
            return root;
        else if(root->val < x)
            root = root->right;
        else
        {
            ceilNode = root;
            root = root->left;
        }
    }
    return ceilNode;
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
    int x = 19;
    node *ceilNode = ceilBst(root, x);
    // node *ceilNode = ceil(root, x);
    if(ceilNode)
        cout<<"ceil of "<<x<<" is "<<ceilNode->val<<endl;
    else 
        cout<<"no ceil exist for "<<x<<endl;
    
    return 0;
}