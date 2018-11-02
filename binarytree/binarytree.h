#ifndef binarytree
#define binarytree

#include<stdio.h>
#include<stdlib.h>

typedef struct node* node_p ;

typedef struct node
{
    node_p left;
    node_p right;
    int data;
}node;

node_p buildtree(int data);
void linknode(r_node_p root , r_node_p Left, r_node_p Right);
void preorder(r_node_p root);//recursion
void postorder(r_node_p root);
void inorder(r_node_p root);

//the recursion has finished , and now begin the iteration

typedef struct i_node* i_node_p;
typedef struct i_stack* i_stack_p;

typedef struct i_node
{
    int data;
    i_node_p next;
}i_node;

typedef struct i_stack
{
    i_node_p top;
}i_stack;

i_stack initstack();
void pushstack(i_stack_p s,int data);
i_stack_p  popstack(i_stack_p s);
int* perorder(node_p root , i_stack_p s);
int* postorder(node_p root , i_stack_p s);
int* inorder(node_p root , i_stack_p s);


#endif
