#include<iostream>
using namespace std;

class IndexTree
{
     public : int *p;
     int size = 0;

     IndexTree(int s)
     {
      p = new int[s + 1];
      for(int i = 1;i <= s;i++)
      {
          p[i] = 0;
      }
      size = s;
     }

     void add(int index,int value)
     {
         while(index < size)
         {
             p[index] += value;
             index += index & -index;
         }
     }

     int sum(int index){
         int ret = 0;
         while(index > 0)
         {
             ret += p[index];
             index -= index & -index;
         }
          return ret;
     }
    
};

int main()
{
    IndexTree Tree(3);
    for(int i = 0;i <= 2;i++){
        Tree.add(i,1);
    }
    cout<<Tree.sum(1);
    return 0;
}