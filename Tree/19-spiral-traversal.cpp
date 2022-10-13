// traverse tree in spiral form (zig-zag traversal)
// left - right, right - left, left - right .....


#include <iostream>
#include <queue>
#include <stack>

#include "binaryTree.h"

using namespace std; 

// time comp : O(n) , but 4n work is there insert in queue, pop from queue, insert in stack , pop from stack 
void zigZagTraversal(node *root)
{
    if(root == NULL) return;
    queue<node *> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    int count ;
    node *temp ;
    cout<<"zigZagTraversal:"<<endl;
    while(!q.empty()) {
        count = q.size();
        for(int i = 0; i < count; i++) {
            temp = q.front();
            q.pop();
            if(reverse)
                s.push(temp->val);
            else
                cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(reverse)
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        cout<<endl;
        reverse = !reverse;
        
    }
}

// using 2 stacks
void zigZag(node *root)
{
    if(root == NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    stack<node *> s1, s2;
    s1.push(root);
    node *temp ;
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            cout<<temp->val<<" ";
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        cout<<endl;
        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            cout<<temp->val<<" ";
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
        cout<<endl;
    }
}


int main()
{
    // construct a random tree from inorder and preorder 
    int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);
    // level order traversal of tree line by line 
    printTreeLineByLine(root);
    
    zigZagTraversal(root);
    zigZag(root);

    return 0;
}