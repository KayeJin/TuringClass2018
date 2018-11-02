#ifndef binarytree
#define binarytree

#include<stdio.h>
#include<stdlib.h>

typedef struct r_node* r_node_p ;//recursion

typedef struct r_node
{
    r_node_p left;
    r_node_p right;
    int data;
}r_node;

r_node_p buildtree(int data);
void linknode(r_node_p root , r_node_p Left, r_node_p Right);
void preorder(r_node_p root);
void postorder(r_node_p root);
void inorder(r_node_p root);


#endif
