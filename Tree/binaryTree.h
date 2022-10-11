#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>

struct node {
    int val;
    node *left ;
    node *right ;
    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};
#endif