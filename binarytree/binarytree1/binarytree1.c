#include "binarytree1.h"

unsigned char checker=0;
snode_p stackBuild()
{
    return NULL;
}

snode_p  stackPush(snode_p head,tnode_p t_pointer)
{
    snode_p newnode=(snode_p)malloc(sizeof(snode));

    newnode->next = head;
    newnode->t_pointer = t_pointer;

    head = newnode;

    return head;
}

snode_p stackPop(snode_p head)
{
    snode_p temp = head;
    head = temp->next;
    free(temp);

    return head;
}

int stackIsEmpty(snode_p head)
{
    return head==NULL; 
}

tnode_p stackTop(snode_p head)
{
    return head->t_pointer;
}

void stackDestory(snode_p head)
{
    while(head)
    {
        head = stackPop(head);
    }
}

tnode_p autoBuildtree(tnode_p root,int data,int floor)
{
    if(floor <= 0 )return NULL;
    root =(tnode_p)malloc(sizeof(tnode));
    root->data=data;
    root->visited = 1;
    root->left=autoBuildtree(root->left, data*2, floor-1);
    root->right=autoBuildtree(root->right, data*2+1, floor-1);
    return root;
}


void visit(tnode_p tnode)//print and lebal
{
    printf("%d ",tnode->data);
    tnode->visited++; 
}

void Newchecker(unsigned char num)
{
    checker = num+1;
}

int Ischecker(tnode_p node)//if haven`t visit,return 1,else return 0;
{
    return node->visited == checker;
}

void treeFrontvisited1(tnode_p root)//recursion
{
    if(!root)return;
    visit(root);
    treeFrontvisited1(root->left);
    treeFrontvisited1(root->right);
}

void treeFrontvisited2(tnode_p root)//iteration
{
    snode_p st = stackBuild();

    tnode_p temp = root;

    while(1)
    {
        if(temp)
        {
            if(temp->right) st =stackPush(st,temp->right) ;
            visit(temp);
            temp = temp->left;
        }
        else if(!stackIsEmpty(st))
        {
            temp = stackTop(st);
            st = stackPop(st);
        }
        else 
        {
            break;
        }
    }
    stackDestory(st);
}

void treeMediumvisited1(tnode_p root)
{
    if(!root)return;
    treeMediumvisited1(root->left);
    visit(root);
    treeMediumvisited1(root->right);
}

void treeMediumvisited2(tnode_p root)
{
    snode_p st = stackBuild();
    Newchecker(root->visited);

    tnode_p temp = root;
    if(temp->right) st = stackPush(st ,temp->right);
    while(!stackIsEmpty(st))
    {
        while(temp->left && !Ischecker(temp->left))
        {
            st = stackPush(st,temp);
            temp = temp->left;
        }
        visit(temp);
        if(temp->right && !Ischecker(temp->right))
        {
            temp = temp->right;
        }
        else 
        {
            temp = stackTop(st);
            st = stackPop(st);
        }
    }
    stackDestory(st);
}

void treeEndvisited1(tnode_p root)
{
    if(!root)return;
    treeEndvisited1(root->left);
    treeEndvisited1(root->right);
    visit(root);
}
void treeEndvisited2(tnode_p root)
{
    snode_p st = stackBuild();
    Newchecker(root->visited);
    tnode_p temp = root;
    st = stackPush(st,root);

    while(!stackIsEmpty(st))
    {
        while(temp->left && !Ischecker(temp->left))
        {
            st = stackPush(st,temp);
            temp = temp->left;
        }
        if(temp->right && !Ischecker(temp->right))
        {
            st = stackPush(st,temp);
            temp =temp->right;
            continue;
        }
        else
        {
            visit(temp);
            temp = stackTop(st);
            st = stackPop(st);
        }
    }
    stackDestory(st);
}

void treeDestory(tnode_p root)
{
    if(!root) return;
    treeDestory(root->left);
    treeDestory(root->right);

    root = NULL;
}
