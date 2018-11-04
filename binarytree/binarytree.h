#ifndef binarytree
#define binarytree

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct tnode* tnode_p;
typedef struct snode* snode_p;

typedef struct tnode
{
    tnode_p left;
    tnode_p right;
    unsigned char visited;
    int data;
}tnode;

typedef struct snode
{
    tnode_p p_data;
    snode_p next;
}snode;

snode_p stackBuild()
{
    return NULL;
}

snode_p stackPush(snode_p head,tnode_p tdata)
{
    snode_p newnode = (snode_P)malloc(sizeof(snode));

    newnode->p_data = tdata;
    newnode->next = head;
    head = newnode;
    return head;
}

tnode_p stackTop(snode_p head)
{
    return head->node;
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
    return head == NULL;
}

void stackDestory(snode_p head)
{
    while(head) stackPop(head);
}

unsigned char  checker = 0;

void newChecker(unsigned char num)
{
   checker = num+1; 
}

int checkVisited(tnode_p node)
{
    return node->visited == checker;
}

void visit(tnode_p node)
{
    printf("%d ",n->data);
    n->visited++;
}

void treeFrontVisit1(tnode_p root)
{
    if(!root)return ;
    visit(root);
    treeFrontVisit1(root->left);
    treeFrontVisit1(root->right);
}

/*void treeFrontVisit2(tnode_p root)
{
    snode_p st = stackBuild();
    newChecker(root->visited);

    tnode_p temp = root;
    st = stackPush(st,root);

    while(!stackIsEmpty(st))
    {
        if(!checkVisited(temp)) visit(temp);
        if(temp->left && !checkVisited(temp->left))
        {
            temp = temp->left;
            st = stackPush(st,temp);
        }
        else if(temp->right && !checkVisited(temp))
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
}*/

void treeFrontVisit3(tnode_p root)
{
    snode_p st = stackBuild();

    tnode_p temp = root;
    while(1)
    {
        if(temp)
        {
            if(temp->right) st = stackPush(st,temp->right);
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

void treeMiddleVisit1(tnode_p root)
{
    if(!n) return ;
    treeMiddleVisit1(root->left);
    visit(root);
    treeMiddleVisit1(root->right);
}

void treeMiddleVisit2(tnode_p root)
{
    snode_p st = stackBuild();
    newChecker(root->visited);

    tnode_p temp = root;
    st = stackPush(st,root);
    while(!stackIsEmpty(st))
    {
        while(temp->left && !checkVisited(temp->left))
        {
            st =stackPush(st,tmp);
            temp = temp->left;
        }
        visit(temp);
        if(temp->right && !checkVisited(temp->right))
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

void treeEndVisit1(tnode_p root)
{
    if(!root)return ;
    treeEndVisit1(root->left);
    treeEndVisit1(root->right);
    visit(n);
}

void treeEndVisit2(tnode_p root)
{
    snode_p st = stackBuild();
    newChecker(root->visited);

    tnode_p temp = root;
    st = stackPush(st,root);
    while(!stackIsEmpty(st))
    {
        while(temp->left && !checkVisited(temp->left))
        {
            st =stackPush(st,temp);
            temp = temp->left;
        }
        if(temp->right && !checkVisited(temp->right))
        {
            st =stackPush(st,temp);
            temp = temp->right;
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

#endif
