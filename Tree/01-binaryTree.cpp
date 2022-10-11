#include <iostream>

using namespace std; 

struct node{
    int val;
    node * left;
    node * right;
    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};



int main()
{
    node *root = new node(10);
    node *node1 = new node(11);
    node *node2 = new node(12);
    
    root->left = node1;
    root->right = node2;
    
    return 0;
}