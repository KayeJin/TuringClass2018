#include "binarytree.h"
node_p buildtree(int data)
{
    node_p newnode = (node_p) malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;

    return newnode;
}
void linknode(node_p root, node_p left, node_p right)
{
    root->left = left;
    root->right = right;
}
void preorder(r_node_p root )//recursion
{
    if(root == NULL) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(r_node_p root)
{
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(r_node_p root)
{
    if(root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// the recursion has finished ,now begin with the iteration


i_stack_p initstack()
{
    i_stack_p ins = (i_stack_p)malloc(sizeof(i_stack));
    if(ins == NULL)
    {
        assert(0);
    }
    ins->top = NULL;
}
void pushstack(i_stack_p s,int data)
{
    i_node_p newnode = (i_node_p) malloc (sizeof(i_node)); 
    newnode
}

