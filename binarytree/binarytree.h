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


snode_p stackBuild();

snode_p stackPush(snode_p head,tnode_p tdata);

tnode_p stackTop(snode_p head);

snode_p stackPop(snode_p head);

int stackIsEmpty(snode_p head);

void stackDestory(snode_p head);


void newChecker(unsigned char num);

int checkVisited(tnode_p node);

void visit(tnode_p node);

void treeFrontVisit1(tnode_p root);

void treeFrontVisit3(tnode_p root);
 
void treeMiddleVisit1(tnode_p root);

void treeMiddleVisit2(tnode_p root);

void treeEndVisit1(tnode_p root);

void treeEndVisit2(tnode_p root);

tnode_p BuildTree(tnode_p root,int data,int floor);

void destroyTree(tnode_p root);

#endif
