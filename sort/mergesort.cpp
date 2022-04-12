#include<iostream>
using namespace std;




void mergesort(int L,int M,int R,int nums[])
{
    int *help = new int[R - L + 1];
    int index = 0;
    int p1 = L;
    int p2 = M + 1;
    while(p1 <= M && p2 <= R)
    { 
          help[index++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
    }
    while(p1 <= M)
    {
        help[index++] = nums[p1++];
    }
    while(p2 <= R)
    { 
        help[index++] = nums[p2++];
    }
    for(int i = 0;i <= R - L;i++)
    {
        nums[i + L] = help[i];
    }
}

void process(int L,int R,int nums[])
{
   if(L == R)
   {
       return;
   }
   int mid = ((R - L)>>1) + L;
   process(L,mid,nums);
   process(mid+1,R,nums);
   mergesort(L,mid,R,nums);
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
      int len = 10;
      int *nums = getrandomnums(len,max,min);
      process(0,len-1,nums);
      for(int i = 0;i < len;i++)
      {
          cout<<nums[i]<<" ";
      }
      return 0;
}