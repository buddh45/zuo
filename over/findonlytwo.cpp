#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;



void onlytwo(int nums[],int len)
{
    int eov = 0;
    for(int i = 0;i < len;i++)
    {
        eov = eov ^ nums[i];
    }   
    int tem = eov & (~eov + 1);
    int onlyone = 0;
      for(int i = 0;i < len;i++)
    {
        if((tem & nums[i]) != 0)
        {
            onlyone ^= nums[i];
        }
    }  
    int other = onlyone ^ eov;
    cout<<onlyone<<" "<<other;
    return;
}





//for text
int main()
{
    int index = 0;
    int max = 10;
    int min = 1;
    int len = 4;
    set<int> hash_set;
    int *nums = new int[len << 1 + 2];
 
 
    int target1 = (rand() % (max - min)) + min;
    nums[index++] = target1;
    hash_set.insert(target1);
    cout<<target1<<endl;
  
  
    int target2 = (rand() % (max - min + 1) + min);
    if(hash_set.find(target2) != hash_set.end())
    {
        target2 = target1 + 1;
    }
    nums[index++] = target2;
    hash_set.insert(target2);
    cout<<target2<<endl;
    

    int randnum = 0;
    for(int i = 0;i < len;i++){
    do{
     randnum = rand() % (max - min + 1) + min;
    }while(hash_set.find(randnum) != hash_set.end());
    cout<<randnum<<" ";
      nums[index++] = randnum;
      nums[index++] = randnum;
      hash_set.insert(randnum);
    }
    cout<<endl;
    for(int i = 0;i < (len << 1) + 2;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    onlytwo(nums,(len << 1) + 2);
    return 0;
}