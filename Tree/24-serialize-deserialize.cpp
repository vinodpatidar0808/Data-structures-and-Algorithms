// serialize and deserialize a binary tree

/// Serialization: converting a tree to a string or array in such a way that it can be converted to tree again.
// Deserialization: Getting a tree back from string or array, we have to use same traversal which we use to serialize.

#include <iostream>
#include <vector>

#include "binaryTree.h"

using namespace std; 

// we will insert INT_MIN for NULL values, 
// serailaization using preorder traversal
// time comp : O(n)
void serializeTree(node *root, vector<int>&ser)
{
    if(root == NULL)
    {
        ser.push_back(INT_MIN);
        return ;
    }
    ser.push_back(root->val);
    serializeTree(root->left, ser);
    serializeTree(root->right, ser);
}

node * deserializeTree(vector<int> &arr)
{
    static int ind = 0;
    if(ind == arr.size())
        return NULL;
    int val = arr[ind++];
    if(val == INT_MIN)
        return NULL;
    node *root = new node(val);
    root->left = deserializeTree(arr);
    root->right = deserializeTree(arr);
    return root;
}

int main()
{
    // int inorder[]  {80,40,90,20,100,50,110,10,60,30,70};
    // int preorder[] {10,20,40,80,90,50,100,110,30,60,70};

    int inorder[]  {30,35,20,45,50,65,75,55,10,60,40,70,90,80,100};
    int preorder[] {10,20,30,35,50,45,55,65,75,40,60,70,80,90,100};

    int n = sizeof(inorder)/sizeof(inorder[0]);
    
    node *root = constructTree(inorder, preorder,0, n-1);    
    printTreeLineByLine(root);

    vector<int> serialize;
    serializeTree(root, serialize);
    // must be same as preorder traversal
    for(auto x : serialize)
        cout<<x<<" ";

    cout<<endl;

    // deserialize
    node *newRoot = deserializeTree(serialize);
    printTreeLineByLine(newRoot);

    return 0;
}