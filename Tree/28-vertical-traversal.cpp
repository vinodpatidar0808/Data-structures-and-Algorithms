// vertical traversal : from left to right, all values on left most vertical line then to next line towards right most vertical line


#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

#include "binaryTree.h"

using namespace std; 

void verticalTraversal(node *root)
{
    if(root == NULL) return;
    map<int , vector<int> > m;
    queue<pair<node*, int>> q;

    q.push({root, 0});
    pair<node*,int> temp;
    node *curr;
    int hd ;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        curr = temp.first;
        hd = temp.second;

        m[hd].push_back(curr->val);
        if(curr->left)
            q.push({curr->left, hd-1});
        if(curr->right)
            q.push({curr->right, hd+1});
    }

    for(auto x : m)
    {
        auto vect = x.second;
        for(auto val : vect)
        {
            cout<<val<<" ";
        }
        cout<<endl;
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
    verticalTraversal(root);
    return 0;
}