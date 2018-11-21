#include<stdio.h>
#include<stdlib.h>

int* factorial(int n,int* returnSize);
int trailingZeroes(int n);

int main()
{
    int n;
    scanf("%d",&n);
    int t = trailingZeroes(n);
    printf("%d ",t);
    return 0;
}
int* factorial(int n,int* returnSize)
{
    int l=50,k=0;
    *returnSize=0;
    int* array=(int*)malloc(sizeof(int)*l);
    array[0]=1;
    for(int i=1;i<=n;i++)
    {
        k=0;
        for(int j=0;j<=(*returnSize);j++)
        {
            array[j]=array[j]*i+k;
            k=array[j]/10;
            array[j]=array[j]%10;
        }
        if(k>0)
        {
            (*returnSize)++;
            array[(*returnSize)]=k;
        }
    }
    return array;
}
int trailingZeroes(int n)
{
    int returnSize;
    int count = 0,k;
    int* array=factorial(n, &returnSize);
    while(returnSize != 1)
    {
        k=array[returnSize];
        if(k=0)
        {
            count++;
        }
        returnSize--;
    }
    return count;
}
