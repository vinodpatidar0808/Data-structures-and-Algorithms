// print sum of all nodes in a vertical line from left to right

// concept of horizontal distance : we take distance of root =0, for left child we add -1 to root and for right child we add +1 to root

#include <iostream>
#include <map>

#include "binaryTree.h"

using namespace std; 


void fillVerticalSum(node *root, int hd, map<int,int> &m){

    if(root == NULL)
        return ;
    fillVerticalSum(root->left, hd-1, m);
    m[hd]+= root->val;
    fillVerticalSum(root->right, hd+1, m);
}


// time comp : O(n*log(hd)) : hd = horizontal distance 
void printVerticalSum(node *root)
{
    map<int, int> m;
    fillVerticalSum(root, 0, m);
    for(auto p : m)
    {
        cout<<p.second<<" ";
    }
    cout<<endl;
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
    printVerticalSum(root);
    return 0;
}