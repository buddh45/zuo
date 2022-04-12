#include <iostream>
#include<cstdlib>
#include<stack>
using namespace std;


int *getrandomnums(int len,int max,int min)
{
    int *nums = new int[len];
    for(int i = 0;i < len;i++)
    {
        nums[i] = rand() % (max - min + 1) + min;
    }
    return nums;
}

void swap(int nums[],int a,int b)
{
    int tem = nums[a];
    nums[a] = nums[b];
    nums[b] = tem;
}

int *paratation1(int L,int R,int nums[])
{
    int *help = new int[2];
    int less = L - 1;
    int more = R;
    int index = 0;
    while(index < more){
        if(nums[index] == nums[R])
        {
            index++;
        }
        else if(nums[index] < nums[R])
        {
            swap(nums,index++,++less);
        }
        else{
            swap(nums,index,--more);
        }
    for(int i = 0;i <= 19;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    }
    swap(nums,R,index);
    help[0] = less;
    help[1] = --index;
    return help;
}

void paratation2(int L,int R,int nums[])//加入了随机值，提高效率
{
    int tem = rand() % (R - L) + L;
    swap(nums,tem,R);
    cout<<tem<<endl;
    paratation1(L,R,nums);
}

class Op{
    public : int l,r;
    Op(int left,int right)
    {
        l = left;
        r = right;
    }
};

void insertsort(int L,int R,int nums[])
{
    for(int i = L+1;i <= R;i++)
    {
        for(int j = i;j >= L && nums[j] > nums[j-1];j--)
        {
            swap(nums,j,j-1);
        }
    }
}

void paratation3(int L,int R,int nums[])//大的排序可以
{
    stack<Op> op;
    int *help = paratation1(L,R,nums);
    for(int i = 0;i <= 19;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<help[0]<<" "<<help[1]<<endl;
    int el = help[0];
    int er = help[1];
    op.push(Op(L,el));
    op.push(Op(er,R));
    while(!op.empty())
    {
       Op o = op.top();
       op.pop();
       if(o.l < o.r){
           if(o.r - o.l <= 6)
           {
               insertsort(o.l,o.r,nums);
           }else{
              help = paratation1(o.l - 1,o.r + 1,nums);
              op.push(Op(o.l,help[0]));
              op.push(Op(help[1],o.r));
           }
       }
   }
} 



int main()
{
    int *nums = getrandomnums(20,20,1);
    for(int i = 0;i <= 19;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    paratation3(0,19,nums);
    for(int i = 0;i <= 19;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}