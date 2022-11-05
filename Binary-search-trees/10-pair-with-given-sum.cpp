// check if a pair with given sum exists in binary search tree or not

#include <iostream>
#include <vector>
#include <unordered_set>

#include "bst.h"

using namespace std; 

void isPairUtil(node *root, vector<int>&inorder)
{
    if(root == NULL)
        return ;
    isPairUtil(root->left, inorder);
    inorder.push_back(root->val);
    isPairUtil(root->right, inorder);
}

// time comp : O(n), space comp : O(n + h) ( h = recursion call stack)
bool isPair(node *root, int sum)
{
    vector<int> inorder;
    isPairUtil(root, inorder);
    int n = inorder.size();
    int first =0, last = n-1;
    
    int curr ;
    while(first< last)
    {
        curr = inorder[first]+inorder[last];
        if(curr == sum)
        {
            return true;
        }    
        else if(curr < sum )
            first++;
        else
            last--;
    }
    return false;
}


// time comp : O(n), space comp : O(n + h) ~= O(n) (if n > h)

bool isPairSum(node *root, int sum, unordered_set<int> &s)
{
    if(root == NULL) return false;

    if(isPairSum(root->left, sum, s))
        return true;
    if(s.find(sum - root->val) != s.end())
        return true;
    else 
        s.insert(root->val);
    return isPairSum(root->right, sum, s);
}

int main()
{
    int inOrder[] {2,3,4,5,6,7,8,9,10,11,12,14,15,16};
    int preOrder[] {10,7,5,3,2,4,6,8,9,12,11,15,14,16};

    int n = sizeof(inOrder) /sizeof(inOrder[0]);
    node *root = constructTree(inOrder, preOrder, 0, n-1);

    int sum = 29;
    cout<<boolalpha;
    cout<<"pair with sum "<<sum<<" exist in BST: "<<isPair(root,sum)<<endl;

    unordered_set<int> s;
    cout<<"pair with sum "<<sum<<" exist in BST: "<<isPairSum(root,sum, s)<<endl;

    return 0;
}