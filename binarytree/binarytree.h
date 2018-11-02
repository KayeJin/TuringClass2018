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

//the recursion has finished , and now begin the iteration

typedef struct i_stack* i_stack_p;

typedef struct i_stack
{
    node_p top;
}i_stack;

i_stack_p initstack();
void pushstack(i_stack_p s,int data);
node_p  popstack(i_stack_p s);
int* i_perorder(node_p root ,i_stack_p s,int len);
int* i_postorder(node_p root ,i_stack_p s,int len);
int* i_inorder(node_p root , i_stack_p s,int len);


#endif
