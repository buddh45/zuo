#include<iostream>
#include<set>
#include<cmath>
#include<cstdlib>
#include <memory.h>
using namespace std;

int maxbits(int nums[],int len)
{
    int max = nums[0];
    for(int i = 1;i < len;i++)
    {
        max = max > nums[i] ? max : nums[i];
    }
    int digit = 0;
    while(max)
    {
        digit++;
        max /= 10;
    }
    return digit;
}



int getdigit(int n,int w)
{
    return (n/(int)pow(10,w-1) % 10);
}

void RadixSort(int nums[],int len,int maxbits)
{
    int Radix = 10;
    for(int w = 1;w <= maxbits;w++)
    {
        int *count = new int[10];
        memset(count,0,10 * sizeof(int));
        for(int i = 0;i < len;i++)
        {
            int j = getdigit(nums[i],w);
            count[j]++;
        }
        for(int i = 1;i < Radix;i++)
        {
            count[i] = count[i] + count[i-1];
        }
        int *help = new int[len];       
        for(int i = len - 1;i >= 0;i--)
        {
            
            int tem = getdigit(nums[i],w);
            int j = count[tem] - 1;
            help[j] = nums[i];
            count[tem]--; 
        }
        for(int i = 0;i < len;i++)
        {
            nums[i] = help[i];
        }
    }
    return;
}




//for text 
int *getrandomnums(int len,int max,int min)
{
    int *nums = new int[len];
    for(int i = 0;i < len;i++)
    {
         nums[i] = (rand() % (max - min + 1)) + min;
         cout<<nums[i]<<" ";   
    }
    cout<<endl;
    return nums;
}

int main()
{
    int max = 10;
    int min = 1;
    int len = 5;
    int *nums = getrandomnums(len,max,min);
    RadixSort(nums,len,maxbits(nums,len));
    for(int i = 0;i < len;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}