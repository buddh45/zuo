#include <iostream>
using namespace std;

void swap(int nums[],int a,int b)
{
    int tem = nums[a];
    nums[a] = nums[b];
    nums[b] = tem; 
}

void heapinsert(int index,int nums[])
{
    while(nums[(index - 1) / 2] < nums[index])
    {
        swap(nums,index,(index - 1) / 2);
    }
    return;
} 

void heapify(int index,int nums[],int heapsize)
{
    int left = 2 * index + 1;
    while(left < heapsize)
    {
        int best = left + 1 < heapsize && nums[left + 1] > nums[left] ? left + 1:left;
        best = nums[best] > nums[index] ? best : index;
        if(index == best)
        {
            break;
        }
        swap(nums,best,index);
        index = best;
        left = 2 * index + 1;
    }
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

void heapsort(int nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        heapinsert(i,nums);
    }
    for(int i = 0;i < len;i++)
    {
        heapify(i,nums,len);
    }
    int heapsize = len;
   swap(nums,0,heapsize-1);
    while(heapsize)
    {
       heapify(0,nums,heapsize);
       swap(nums,--heapsize,0);
    }
    return;
}




int main()
{

   int *heap = getrandomnums(10,1,10);
   heapsort(heap,10);
   for(int i = 0;i < 10;i++)
   {
       cout<<heap[i]<<" ";
   }
    return 0;
}