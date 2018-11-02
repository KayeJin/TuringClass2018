#include "binarytree.h"

int main()
{
    r_node_p root  = buildtree(3);
    r_node_p left1 = buildtree(2);
    r_node_p right1= buildtree(4);
    r_node_p left1left = buildtree(1);
    r_node_p left1right= buildtree(3);
    r_node_p right1left = buildtree(3);
    r_node_p right1right = buildtree(5);

    linknode(root,left1,right1);
    linknode(left1,left1left,left1right);
    linknode(right1,right1left,right1right);

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);

    return 0;
}

