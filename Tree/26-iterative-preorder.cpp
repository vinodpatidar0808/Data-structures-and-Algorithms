#include <iostream>
#include <stack>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n), space comp : O(n), 
void preorderIterative(node *root)
{
    if(root == NULL) return;
    stack<node *> s;
    s.push(root);
    while(!s.empty())
    {
        node *curr = s.top();
        s.pop();
        cout<<curr->val<<" ";
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}


// time comp : O(n), space comp : O(h), 
void iterativePreorder(node *root)
{
    if(root == NULL) return;
    stack<node *> s;
    node *curr = root;
    while(curr != NULL && !s.empty())
    {
        while(curr != NULL)
        {
            cout<<curr->val<<" ";
            if(curr->right)
                s.push(curr->right);
            curr = curr->left;
        }
        if(!s.empty())
        {
            curr = s.top();
            s.pop();
        }

    }
}


int main()
{

    int inorder[]  {80,40,90,20,100,50,110,10,60,30,70};
    int preorder[] {10,20,40,80,90,50,100,110,30,60,70};

    // int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    // int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);    
    // printTreeLineByLine(root);    
    preorderIterative(root);
    return 0;
}