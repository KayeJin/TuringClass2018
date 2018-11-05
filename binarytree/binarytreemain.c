#include "binarytree.h"

int main()
{
    tnode_p root = NULL;
    root = BuildTree(root,1,4);

    treeFrontVisit1(root);
    printf("\n");
//    treeFrontVisit2(root);
//    printf("\n");
    treeFrontVisit3(root);
    printf("\n");
    printf("\n");
    treeMiddleVisit1(root);
    printf("\n");
    treeMiddleVisit2(root);
    printf("\n");
    printf("\n");
    treeEndVisit1(root);
    printf("\n");
    treeEndVisit2(root);
    printf("\n");

    return 0;
}


