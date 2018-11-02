#ifndef binarytree
#define binarytree

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node* node_p ;

typedef struct node
{
    node_p left;
    node_p right;
    node_p next;
    int data;
}node;

node_p buildtree(int data);
void linknode(node_p root , node_p Left, node_p Right);
void preorder(node_p root);//recursion
void postorder(node_p root);
void inorder(node_p root);


#endif
