// given a binary tree leaf, find maximum time taken to burn the tree from given leaf
#include <iostream>

#include "binaryTree.h"

using namespace std; 

int res = 0;
int burnTree(node *root, int leaf, int &maxDist)
{
    if(root == NULL) return 0;
    if(root->val == leaf)
    {
        maxDist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burnTree(root->left, leaf, ldist);
    int rh = burnTree(root->right, leaf, rdist);
    if(ldist != -1)
    {
        maxDist = ldist +1;
        res = max(res, maxDist+rh);
    }
    else if(rdist != -1)
    {
        maxDist = rdist +1;
        res = max(res, maxDist+lh);
    }

    return max(lh, rh)+1;
}

int main()
{
    int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);
    // printTreeLineByLine(root); 

    int leaf = 60;
    int maxDist = -1;
    burnTree(root, leaf, maxDist);
    cout<<"time to burn tree: "<<res<<endl;
    return 0;
}