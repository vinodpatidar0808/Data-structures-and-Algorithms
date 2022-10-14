// diameter : number of nodes on longest path between 2 leaf nodes
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "binaryTree.h"
using namespace std; 

int height(node *root)
{
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right))+1;
}

// time comp : O(n^2) 
int diameter(node * root)
{
    if(root == NULL) return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max({d1, d2, d3});
}

unordered_map<node *,int> heights;
int fillHeight(node * root)
{
    if(root == NULL)    return 0;
    heights[root] = 1 + max(fillHeight(root->left), fillHeight(root->right));
    return heights[root];
}


// time comp : O(n), space comp : O(n)
int diameter2(node * root)
{
    if(root == NULL) return 0;
    int d1 = 1 + heights[root->left]+ heights[root->right];
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max({d1, d2, d3});
}

// approach 3 : O(n)
// returns height but sets diameter in res variable
int diameter3(node * root, int &res)
{
    if(root == NULL) return 0;
    int lh = diameter3(root->left,res);
    int rh = diameter3(root->right,res);
    res = max(res, 1+lh+rh);
    return 1 + max(lh, rh);
}



int main()
{
    int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);
    printTreeLineByLine(root);   

    cout<<"diameter of binary tree is "<<diameter(root)<<endl;
    fillHeight(root);
    cout<<"diameter of binary tree is "<<diameter2(root)<<endl;
    int d = 0;
    diameter3(root, d);
    cout<<"diameter of binary tree is "<<d<<endl;


    return 0;
}