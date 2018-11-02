#include "binarytree.h"
node_p buildtree(int data)
{
    node_p treenode = (node_p) malloc(sizeof(node));
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->data = data;

    return treenode;
}
void linknode(node_p root, node_p left, node_p right)
{
    root->left = left;
    root->right = right;
}
void preorder(node_p root )//recursion
{
    if(root == NULL) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node_p root)
{
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(node_p root)
{
    if(root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


