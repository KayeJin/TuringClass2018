#include"binarytree1.h"

int main()
{
    tnode_p root = NULL;
    int floor = 3;
    root=autoBuildtree(root,1,3);

    treeFrontvisited1(root);
    printf("\n");
    treeFrontvisited2(root);
    printf("\n\n");
    treeMediumvisited1(root);
    printf("\n");
    treeMediumvisited2(root);
    printf("\n\n");
    treeEndvisited1(root);
    printf("\n");
    treeEndvisited2(root);

    treeDestory(root);
    return 0;

}
