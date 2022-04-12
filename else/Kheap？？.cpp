#include <iostream>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<array>
#include<string.h>
using namespace std;

void Kheap1(int nums[],int limit,int len)
{
    int *ans = new int[len];
    priority_queue<int> tem;
    int i = 0;
    int index = 0;
    for(;i < limit - 1;i++)
    {
         tem.push(nums[i]);
    }
    for(;i < min(len-1,limit-1);i++){
        tem.push(nums[i]);
        ans[index++] = tem.top();
        tem.pop();
    }
    while(!tem.empty())
    {
        ans[index++] = tem.top();
        tem.pop(); 
    }
    return;
}

//for text
int *getrandomarrs(int max,int min,int len)
{
    int *nums = new int[len];
    for(int i = 0;i < len;i++)
    {
        nums[i] = rand() % (max - min + 1) + min; 
    }
    return nums;
}

//for text
void print(int nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout<<nums[i]<<" ";
    }
    return;
}

//for text
int *copy(int nums[],int len)
{
    int *newnum = new int[len];
    for(int i = 0;i < len;i++)
    {
        newnum[i] = nums[i];
    }
    return newnum;
}

void swap(int nums[],int a,int b)
{
    int tem = nums[a];
    nums[a] = nums[b];
    nums[b] = tem;
}

void insertsort(int nums[],int len)
{
    for(int i = 1;i < len;i++)
   {
       for(int j = i;j >= 1 && nums[j] < nums[j-1];j--)
       {
           swap(nums,j,j-1);
       }
   }
   return;
}

void Kswap(int nums[],int len,int limit)
{
     int i =0;
     bool *isswap = new bool[len];
     memset(isswap,0,len);
     for(int i = 0;i < len;i++){
         int k = min((rand() % limit) + i,len-1);
         if(!isswap[k] && !isswap[i])
         {
             swap(nums,k,i);
             isswap[i] = true;
             isswap[k] = true;
         }
     }
    return;
}

int main()
{
    int max = 10;
    int min = 1;
    int limit = 3;
    int len = 5;
    int *nums = getrandomarrs(max,min,len);
    insertsort(nums,len);
    int *nums1 = copy(nums,len);
    Kswap(nums,len,limit);
    print(nums1,len);
    Kheap1(nums,limit,len);
    cout<<endl;
    print(nums,len);
    return 0;
}