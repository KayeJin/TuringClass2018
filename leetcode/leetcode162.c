#include<stdio.h>

int findPeakElement(int* nums, int numsSize);
int findpeak(int* nums,int head,int tail);
int main()
{
    int nums[4]={1,2,3,1};
    int t= findPeakElement(nums,4);
    
    printf("%d",t);
    return 0;
}
/*int findPeakElement(int* nums , int numsSize)
{
    for(int i=1;i<numsSize-2;i++)
    {
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
        {
            return i;
        }
    }
}*///超时
int findPeak(int* nums,int head,int tail)
{
    int mid = (head+tail)/2;
    if(nums[mid]<nums[mid-1]) findPeak(nums,head,mid-1);
    else if(nums[mid]<nums[mid+1]) findPeak(nums,mid+1,tail);
    else  return mid;
}
int findPeakElement(int* nums,int numsSize)
{
    if(numsSize == 1) return 0;
    if(numsSize == 2)
    {
        if(nums[0]>nums[1]) return 0;
        else return 1;
    }
    else
    {
        int t= findPeak(nums,1,numsSize);
        if(t == numsSize) return t-1;
        return t;
    }
}
