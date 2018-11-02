#include "binarytree.h"

int main()
{
    node_p root  = buildtree(3);
    node_p left1 = buildtree(2);
    node_p right1= buildtree(4);
    node_p left1left = buildtree(1);
    node_p left1right= buildtree(3);
    node_p right1left = buildtree(3);
    node_p right1right = buildtree(5);

    linknode(root,left1,right1);
    linknode(left1,left1left,left1right);
    linknode(right1,right1left,right1right);
    //build and link a tree
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    //the recursion has finished , and the iterstion begin
    
     return 0;
}

