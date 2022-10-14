// find lowest common ancestor level wise 

#include <iostream>
#include <vector>

#include "binaryTree.h"

using namespace std; 

bool findPath(node *root, vector<node *> &path, int n)
{
    if(root == NULL) return false;
    path.push_back(root);
    if(root->val == n)
        return true;
    if(findPath(root->left, path, n) || findPath(root->right, path, n))
        return true;
    path.pop_back();
    return false;
}

// time comp : O(n) : 3 traversal of tree
// aux space : O(n)
node *lca(node *root, int n1, int n2)
{
    vector<node *> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return NULL;
    int i ;
    int s1 = path1.size()-1;
    int s2 = path2.size()-1;
    for(i = 0; i<s1 && i<s2;i++)
    {
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    }
    return path1[i];
}

// assuming both n1 and n2 exist inside tree
// time : O(n) : 1 traversal of tree, aux space : O(h)
node *lowestCommonAncestor(node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->val== n1 || root->val == n2)
        return root;
    node *lca1 = lowestCommonAncestor(root->left, n1, n2);
    node *lca2 = lowestCommonAncestor(root->right, n1, n2);
    // one value in left side of root other in right side
    if(lca1 && lca2)
        return root;

    // both values in left side of root
    if(lca1)
        return lca1;
    else 
        return lca2;

}


int main()
{
    int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);
    printTreeLineByLine(root);   

    int n1 = 60;
    int n2 = 100;
    node *lcaNode = lca(root, n1, n2);
    if(lcaNode==NULL)
        cout<<"no lca of "<<n1<<" and "<<n2<<endl;
    else
        cout<<"lca of "<<n1<<" and "<<n2<<" is: "<<lcaNode->val<<endl;

    node *lcaNode2 = lowestCommonAncestor(root, n1, n2);
    if(lcaNode2==NULL)
        cout<<"no lca of "<<n1<<" and "<<n2<<endl;
    else
        cout<<"lca of "<<n1<<" and "<<n2<<" is: "<<lcaNode2->val<<endl;


    return 0;
}
