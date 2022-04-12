#include <iostream>
using namespace std;

//找到第一个等于target位置

void swap(int nums[],int i,int j)
{
    int tem = nums[i];
    nums[i] = nums[j];
    nums[j] = tem;
}



int BSExist(int nums[],int len,int target)
{
    int L = 0;
    int R = len - 1;
    int mid = 0;
    while(R > L)
    {
        mid = L + (R - L)>>1;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            L = mid  + 1;
        }
        else{
            R = mid - 1;
        }
    }
    return len;
}

int *getrandomnums(int len,int max,int min)
{
    int *nums = new int[len];
    for(int i = 0;i < len;i++)
    {
        nums[i] = rand() % (max - min + 1) + min;
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
   int *nums = new int[len];
   nums = getrandomnums(len,max,min);
   for(int i = 1;i < len;i++)
   {
       for(int j = i;j >= 1 && nums[j] < nums[j-1];j--)
       {
           swap(nums,j,j-1);
       }
   }
   for(int i = 0;i < len;i++)
   {
       cout<<nums[i]<<" ";
   }
   int ans = BSExist(nums,len,5);
   if(ans == len)
   {
       cout<<"No";
   }
   else{
       cout<<ans;
   }
    return 0;
}