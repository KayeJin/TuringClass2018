#include "binarytree.h"

r_node_p buildtree(int data)
{
    r_node_p newnode = (r_node_p) malloc(sizeof(r_node));
    newnode->left = null;
    newnode->right = null;
    newnode->data = data;

    return newnode;
}
void linknode(r_node_p root, r_node_p left, r_node_p right)
{
    root->left = left;
    root->right = right;
}
void preorder(r_node_p root)
{
    if(root == null) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(r_node_p root)
{
    if(root == null) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(r_node_p root)
{
    if(root == null) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

