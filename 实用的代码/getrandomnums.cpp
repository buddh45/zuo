#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;




//去重加入hashset
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