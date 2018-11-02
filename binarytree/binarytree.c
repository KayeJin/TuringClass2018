#include "binarytree.h"
node_p buildtree(int data)
{
    node_p treenode = (node_p) malloc(sizeof(node));
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->data = data;

    return treenode;
}
void linknode(node_p root, node_p left, node_p right)
{
    root->left = left;
    root->right = right;
}
void preorder(r_node_p root )//recursion
{
    if(root == NULL) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(r_node_p root)
{
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(r_node_p root)
{
    if(root == NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// the recursion has finished ,now begin with the iteration


i_stack_p initstack()
{
    i_stack_p ins = (i_stack_p)malloc(sizeof(i_stack));
    if(ins == NULL)
    {
        assert(1);
    }
    ins->top = NULL;
}
void pushstack(i_stack_p s,int data)
{
    i_node_p newnode = (i_node_p) malloc (sizeof(i_node)); 
    newnode->data = data;
    newnode->next = s->top;

    s->top = newnode;
}

i_node_p popstack(i_stack_p s)
{
    if(s->top == NULL)
    {
        assert(1);
    }
    i_node_p temp = s->top;
    s->top = temp->next;
    return temp;

}

int* preorder(node_p root,i_stack_p s,int len)
{
    int p=0;
    int* array = (int*) malloc(sizeof(int)*len);
    while(s->top != NULL )
    {
        if(root != NULL)
        {
            array[p]=root;
            p++;
            pushstack(s,root->data);
            root = root->left;
        }else
        {
            i_node_p node = popstack(s);
            root = node->right;
        }
    }
    return array;
}

int* inorder(node_p root,i_stack_p s,int len)
{
    int* array = (int*) malloc(sizeof(int)*len);
    int p=0;
    while(p != len)
    {
        if(root->left != NULL)
        {
            pushstack(s,root->data);
            root = root->left;
        }else
        {
            array[p] = root->data;
            p++;
            if(root->right == NULL)
            {
                if(s->top == NULL)
                {
                    assert(1);
                }
                i_node_p node = popstack(s);
                array[p] = node->data;
                root = node->right;
            }

        }
    }
    return array;
}

int* postorder(node_p root , i_stack_p s, int len)//two ways
{
    int* array=(int*)malloc(sizeof(int)*len);
    int p=0;
    pushstack(s,root->data);
    while(p != len)
    {
        i_stack_p node = popstack(s);
        array[p]=node->data;
        p++;
        root = node;
        if(root->left != NULL) pushstack(s,root->left->data);
        if(root->right != NULL) pushstack(s,root->right->data);
    }
    return array;
}


