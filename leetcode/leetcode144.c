#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct Treenode* tnode_p;
typedef struct snode* snode_p;
typedef struct stack* stack_p;
typedef struct Treenode
{
    int data;
    tnode_p left;
    tnode_p right;
}tnode;
typedef struct snode
{
    snode_p next;
    tnode_p p;
}snode;

typedef struct stack
{
    snode_p top;
}stack;

tnode_p  buildtree(int data);
void linknode(tnode_p root,tnode_p left,tnode_p right);
stack_p initstack();
void pushstack(stack_p s,tnode_p t);
tnode_p popstack(stack_p s);
int* preorder(tnode_p root,int len);

int main()
{ 
    tnode_p root  = buildtree(3);
    tnode_p left1 = buildtree(2);
    tnode_p right1= buildtree(4);
    tnode_p left1left = buildtree(1);
    tnode_p left1right= buildtree(3);
    tnode_p right1left = buildtree(3);
    tnode_p right1right = buildtree(5);

    linknode(root,left1,right1);
    linknode(left1,left1left,left1right);
    linknode(right1,right1left,right1right);

    int* array = preorder(root,7);

    for(int i=0;i<7;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
tnode_p buildtree(int data)
{
    tnode_p treenode = (tnode_p) malloc(sizeof(tnode));
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->data = data;

    return treenode;
}
void linknode(tnode_p root, tnode_p left, tnode_p right)
{
    root->left = left;
    root->right = right;
}
stack_p initstack()
{
    stack_p ins = (stack_p)malloc(sizeof(snode));
    ins->top = NULL;

    return ins;
}

void pushstack(stack_p s,tnode_p t)
{
    snode_p newnode = (snode_p)malloc(sizeof(snode));
    newnode->p = t;
    newnode->next = s->top;

    s->top = newnode; 
}
tnode_p popstack(stack_p s)
{
    if(s->top == NULL)
    {
        assert(1);
    }
    tnode_p temp = s->top->p;
    s->top = s->top->next;

    return temp;
}

int* preorder(tnode_p root,int len)
{
    int* array1 = (int*)malloc(sizeof(int)*len);
    int p=0;
    stack_p ins = initstack();
    pushstack(ins,root);
    while(ins->top != NULL)
    {
        root = popstack(ins);
        array1[p] = root->data;
        p++;
        if(root->right != NULL) pushstack(ins ,root->right); 
        if(root->left != NULL) pushstack(ins,root->left);
    }
    return array1;
}


