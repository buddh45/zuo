#include<iostream>
using namespace std;
class SegmentTree{
     public : int N,*arrs,*sum,*change,*lazy;
     bool *update;
     SegmentTree(int n,int nums[])
     {
          N = n;
          sum = new int[N << 1 | 1];
          update = new bool[N << 1 | 1];
          lazy = new int[N << 1 | 1];
          change = new int[N << 1 | 1];
          arrs = new int[N];
          for(int i = 1;i <= n;i++)
          {
               arrs[i] = nums[i - 1];
          }
     }

     void pushup(int rt)
     {
          arrs[rt] = arrs[rt << 1 | 1] + arrs[rt << 1];
     }

     void pushdown(int rt,int ln,int rn)
     {
          if(update[rt])
          {
            update[rt << 1] = true;
            update[rt << 1 | 1] = true;
            change[rt<< 1 | 1] = change[rt];
            change[rt << 1] = change[rt];
            sum[rt << 1] = ln * update[rt];
            sum[rt << 1 | 1] = rn * update[rt];
            lazy[rt << 1] = 0;
            lazy[rt << 1 | 1] = 0;
          }
          if(lazy[rt]){
               sum[rt] += 
          }
     }
};