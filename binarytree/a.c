#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct t_node* t_node_p ;
typedef struct stack* stack_p;
typedef struct s_node* s_node_p;
typedef struct t_node
{
    t_node_p left;
    t_node_p right;
    int data;
}t_node;

typedef struct s_node
{
    s_node_p next;
    t_node_p p;
}s_node;

typedef struct stack
{
    s_node_p top;
}stack;

t_node_p buildtree(int data);
stack_p initstack();
void pushstack(stack_p s,t_node_p n);
t_node_p popstack(stack_p s);
void linknode(t_node_p root,t_node_p left,t_node_p right);
int*  preorder(t_node_p root,int len);
int* inorder(t_node_p root,int len);
//int* postorder(t_node_p root,int len);

int main()
{
    t_node_p root  = buildtree(3);
    t_node_p left1 = buildtree(2);
    t_node_p right1= buildtree(4);
    t_node_p left1left = buildtree(1);
    t_node_p left1right= buildtree(3);
    t_node_p right1left = buildtree(3);
    t_node_p right1right = buildtree(5);

    linknode(root,left1,right1);
    linknode(left1,left1left,left1right);
    linknode(right1,right1left,right1right);

    int *array1 = preorder(root,7);
    int *array2 = inorder(root,7);
//   int *array3 = postorder(root,7);
    for(int i=0;i<7;i++)
    {
        printf("%d ",array1[i]);
    }
    for(int i=0;i<7;i++)
    {
        printf("%d ",array2[i]);
    }
    return 0;

}

t_node_p buildtree(int data)
{
    t_node_p treenode = (t_node_p) malloc(sizeof(t_node));
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->data = data;

    return treenode;
}

void linknode(t_node_p root, t_node_p left, t_node_p right)
{
    root->left = left;
    root->right = right;
}

stack_p initstack()
{
    stack_p ins = (stack_p)malloc(sizeof(s_node));
    ins->top = NULL;
    return ins;
} 

void pushstack(stack_p s, t_node_p t)
{
    s_node_p newnode = (s_node_p)malloc(sizeof(s_node));
    newnode->p = t;
    newnode->next = s->top;

    s->top = newnode;
}

t_node_p popstack(stack_p s)
{
    if(s->top == NULL)
    {
        assert(1);
    }
    t_node_p temp = s->top->p;
    s->top = s->top->next;
    return temp;
}
int* preorder(t_node_p root,int len)
{
    int p=0;
    int* array1 = (int*)malloc(sizeof(int)*len);
    if(root == NULL) return array1;
    stack_p ins = initstack();
    pushstack(ins,root);
    while(ins->top != NULL)
    {
        root = popstack(ins);
        array1[p] = root->data;
        p++;
        if(root->right != NULL) pushstack(ins,root->right);
        if(root->left != NULL) pushstack(ins,root->left);
    }
    return array1;
}
int* inorder(t_node_p root,int len)
{
    int p=0;
    int* array2 = (int*)malloc(sizeof(int)*len);
    stack_p ins = initstack();
    while(ins->top != NULL || root != NULL)
    {
        if(root != NULL)
        {
            pushstack(ins,root);
            root = root->left;
        }
        else
        {
            root = popstack(ins);
            array2[p] = root->data;
            p++;
            root = root->right;
        }
    }
    return array2;
}

int* postorder(t_node_p root,int len)
{
    int p=0;
    int* array3 = (int*)malloc(sizeof(int)*len);
    stack_p ins = initstack();
    t_node_p lastnode = NULL;
    t_node_p peeknode ;
    while(ins->top != NULL || root != NULL)
    {
        if(root != NULL)
        {
            pushstack(ins,root);
            root = root->left;
        }
        else
        {
            peeknode = 

        }
    }
}


