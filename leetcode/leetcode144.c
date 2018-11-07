#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode*  right;
    int data;
};
struct StackNode
{
    struct StackNode*  next;
    struct TreeNode*  t_pointer;
};

//int*  Buildtree(int* array,int len);
struct TreeNode* BuildTree(int data);
struct StackNode* stackBuild();
struct StackNode*  stackPush(struct StackNode*  s,struct TreeNode* p);
struct TreeNode* stackTop(struct StackNode*  s);
struct StackNode*  stackPop(struct StackNode* s);
int*  preorder(struct TreeNode* root,int* array);
int IsEmpty(struct StackNode* s);

/*int main()
{
    char c;
    int* array = (int*)malloc(sizeof(int));
    printf("please stop with '#'");
    while(c != '#')
    {
        scanf("%c ",&c);
        array[p]=c;
        p++;
    }
    Buildtree(array,p);
    
    

}*/
int main()
{
    int array[]={1,2,3};
    int* returnSize;
    struct TreeNode* root = BuildTree(1);
    struct TreeNode* Right = BuildTree(2);
    struct TreeNode* Rightleft = BuildTree(3);

    root->left = NULL;
    root->right = Right;
    Right->left = Rightleft;

    int* array1 = preorder(root,returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d ",array1[i]);
    }
    return 0;
}
struct TreeNode* BuildTree(int data)
{
    struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;

}
struct StackNode* stackBuild()
{
    return NULL;
} 
struct StackNode* stackPush(struct StackNode* s,struct TreeNode* p)
{
    struct StackNode* newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
    newnode->t_pointer = p;
    newnode->next = s;

    s= newnode;
    
    return s;
}


struct TreeNode* stackTop(struct StackNode* s)
{
    return s->t_pointer;
}
struct StackNode* stackPop(struct StackNode* s)
{
    struct StackNode* temp = s;
    s=s->next;
    free(temp);
    return s;
}
int IsEmpty(struct StackNode* s)
{
    return s==NULL;
}


int* preorder(struct TreeNode* root,int* returnSize)
{
    int l=100;
    array = (int*)malloc(sizeof(int)*l);
    struct StackNode* st = stackBuild();
    struct TreeNode* temp = root;

    while(1)
    {
        if(temp)
        {
            if(temp->right) st = stackPush(st,temp->right);
            array[(*returnSize)]=temp->data;
            (*returnSize)++;
            temp=temp->left;
        }
        else if(!IsEmpty(st))
        {
            temp = stackTop(st);
            st = stackPop(st);
        } 
        else
        {
            break;
        }
    }
    return array;
}
