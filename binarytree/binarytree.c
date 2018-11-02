#include "binarytree.h"

r_node_p buildtree(int data)
{
    r_node_p newnode = (r_node_p) malloc(sizeof(r_node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;

    return newnode;
}
void linknode(r_node_p root, r_node_p Left, r_node_p Right)
{
    root->left = Left;
    root->right = Right;
}
void preorder(r_node_p root)
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
