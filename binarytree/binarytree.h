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

//the recursion has finished , and now begin the iteration

typedef struct i_node* i_node_p;
typedef struct i_stack* i_stack_p;

typedef struct i_node
{
    i_node_p left;
    i_node_p right;
    int data;
}i_node;

typedef struct i_stack
{
    i_stack_p top;
}i_stack;

i_node_p buildtree(int data);
void linknode(i_node_p root , i_node_p Left , i_node_p Right);

i_stack initstack();
void pushstack(i_stack_p s,int data);
int popstack(i_stack_p s);
int* perorder();
int* postorder();
int* inorder();


#endif
