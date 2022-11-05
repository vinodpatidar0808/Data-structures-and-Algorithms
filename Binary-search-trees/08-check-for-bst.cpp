// check whether given tree is a binary search tree or not

#include <iostream>

#include "bst.h"

using namespace std; 


// time comp: O(n)
bool checkBst(node *root, int minVal=INT_MIN, int maxVal=INT_MAX ) 
{
    if(root == NULL)
        return true;
    return ((root->val >minVal) && (root->val<maxVal) && checkBst(root->left, minVal, root->val) && checkBst(root->right, root->val, maxVal));
}


void isBstUtil(node *root, vector<int> &arr)
{
    if(root == NULL)
        return ;
    isBstUtil(root->left, arr);
    arr.push_back(root->val);
    isBstUtil(root->right, arr);
}

// approach 2 : inorder traversal of a binary search tree is always in sorted order 
// time comp: O(n), space comp : O(n)
bool isBst(node *root)
{
    if(root == NULL)
        return true;
    vector<int> arr;
    isBstUtil(root, arr);

    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;

}

// without using auxilliary array

bool checkForBst(node *root)
{
    if(root == NULL)
        return true;
    static int prev = INT_MIN;
    if(checkForBst(root->left)==false)
        return false;
    if(root->val <= prev)
        return false;
    prev = root->val;
    return checkForBst(root->right);
}


int main()
{

    int inOrder[] {2,3,4,5,6,7,8,9,10,11,12,14,15,16};
    int preOrder[] {10,7,5,3,2,4,6,8,9,12,11,15,14,16};
    
    // int inOrder[] {7,20,11,35,45}; 
    // int preOrder[] {20,7,35,11,45};

    int n = sizeof(inOrder)/sizeof(inOrder[0]);
    node *root = constructTree(inOrder, preOrder, 0, n-1);
    cout<<boolalpha;
    cout<<"is tree BST? "<<checkBst(root)<<endl;
    cout<<"is tree BST? "<<isBst(root)<<endl; 
    cout<<"is tree BST? "<<checkForBst(root)<<endl; 

    return 0;
}