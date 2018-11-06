#ifndef binarytree1
#define binarytree1

#include<stdio.h>
#include<stdlib.h>

typedef struct tnode* tnode_p;
typedef struct snode* snode_p;

typedef struct tnode
{
    int data;
    tnode_p left;
    tnode_p right;
    unsigned char visited;
}tnode;

typedef struct snode
{
    snode_p next;
    tnode_p t_pointer;
}snode;

snode_p stackBuild();//build a stack immediately by stacknodes
snode_p stackPush(snode_p head,tnode_p t_pointer);//the parameter are stacknode and the pointer of treenode
snode_p stackPop(snode_p head);//need the head 
tnode_p stackTop(snode_p head);//get the top data
int stackIsEmpty(snode_p head);
void stackDestory(snode_p head);//destory the stack 

tnode_p autoBuildtree(tnode_p root,int data,int floor);//this only for full binary tree and the data has some rule;
void treeDestory(tnode_p root);

void visit(tnode_p tnode);
void Newchecker(unsigned char num);
int Ischecker(tnode_p node);


void treeFrontvisited1(tnode_p root);
void treeFrontvisited2(tnode_p root);

void treeMediumvisited1(tnode_p root);
void treeMediumvisited2(tnode_p root);

void treeEndvisited1(tnode_p root);
void treeEndvisited2(tnode_p root);

#endif

