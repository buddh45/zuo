#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

int onlyone(int nums[],int len)
{
    int eov = 0;
    for(int i = 0;i < len;i++)
    {
        eov ^= nums[i];
        cout<<eov<<" ";
    }
    return eov;
}

//for text


int main()
{
    int len = 4;  //有4个不同的数字，他们的长度分别为1到10之间，只有一个数出现了1次，其他数字出现了2次
    int min = 1;
    int max = 10;
    set<int> my_set;
    int *nums = new int[len << 1 + 1];
    int target = (rand() % (max - min + 1)) + min;//寻找本次的在最大值和最小值之间的某个值
    int index = 1;                                 //放入数组的标记
    cout<<target<<" ";
    my_set.insert(target);
    nums[0] = target;
    int randdomnum = -1;
    for(int i = 1;i <= 4;i++){
    do
    {
        randdomnum = (rand() % (max - min + 1)) + min;
    }while(my_set.find(randdomnum) != my_set.end());
        nums[index++] = randdomnum;
        nums[index++] = randdomnum;
        my_set.insert(randdomnum);
    }
    for(int i = 0; i < len * 2 + 1;i++)
    {
        cout<<nums[i] <<" ";
    }
    if(onlyone(nums,len << 1 + 1) == target)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}