#include <iostream>
using namespace std;

//找到大于等于target的某个位置

int BSNearleft(int nums[],int len,int target)
{
    int L = 0;
    int R = len - 1;
    int mid = 0;
    int index = -1;

    while(L <= R)
    {
        mid = L + ((R - L)>>1);
        if(nums[mid] >= target)
        {
             index = mid;
             R = mid - 1;
        }
        else{
              L = mid + 1;
        }
    }
    return index;
}



//for test
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

//for text

void swap(int nums[],int i,int j)
{
    int tem = nums[i];
    nums[i] = nums[j];
    nums[j] = tem;
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
   cout<<endl;
   cout<<BSNearleft(nums,len,2);
    return 0;
}