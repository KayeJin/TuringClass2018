#include "binarytree1.h"

snode_p stackBuild(snode_p head)
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
    head = head->next;
    free(temp);

    return head;
}

int stackIsEmpty(snode_p head)
{
    return head;
}

tnode_p stackTop(snode_p head)
{
    return head->t_pointer;
}

void stackDestory(snode_p head)
{
    when(head)
    {
        head = stackPop(head);
    }
}

tnode_p autoBuildtree(tnode_p root,int data,int floor)
{
    if(floor <=0 )return NULL;
    tnode_p newnode=(tnode_p)malloc(sizeof(tnode));
    newnode->data=data;
    newnode->visited = 1;
    newnode->left=autoBuildtree(root->left,int data*2,int floor-1);
    newnode->right=autoBuildtree(root->right,int data*2+1,int floor-1);
    return root;
}

void treeDestory(tnode_p root)
{
    if(!root) return;
    treeDestory(root->left);
    treeDestory(root->right);
    free(root);
    root = NULL;
}

void visit(tnode_p tnode)//print and lebal
{
    printf("%d ",tnode->data);
    tnode->visited++; 
}

void Newchecker(tnode_p node)
{
    checker = node->visited++;
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
    snode_p st = stackBuild(st);

    tnode_p temp = root;
    Newchecker(root);

    while(1)
    {
        if(temp)
        {
            if(temp->right && !Ischecker(temp->right)) st=stackPush(st,temp->right);
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
    visit(root);
    treeMediumvisited1(root->left);
    treeMediumvisited1(root->right);
}

void treeMediumvisited2(tnode_p root)
{
    snode_p st = stackBuild(root);
    Newchecker(root);

    tnode_p temp = root;
    if(temp->right) st = stackPush(st ,temp->right);
    while(!stackIsEmpty(st))
    {
        if(temp->left && !Ischecker(temp->left))
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
}
void treeEndvisited2(tnode_p root)
{
    snode_p st = stackPush();
    Newchecker(root);
    tnode_p temp = root;
    st = stackPush(st,root);

    while(!stackIsEmpty(st))
    {
        if(temp->left && !Ischecker(temp->left))
        {
            st = stackPush(st,temp->left);
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
