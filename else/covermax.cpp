#include <iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;



class line{
public:     int l;
     int r;
     void setl(int l)
     {
         this->l = l;
     }
     void setr(int r)
     {
         this->r = r;
     }
};

bool comparator(line l1,line l2)
{
    return l1.l < l2.l;
}


vector<line> getline(int max1,int min1,int len)
{
    vector<line> lines;
   for(int i = 0;i < len;i++)
   {
       int a = rand() % (max1 - min1 + 1) + min1;
       int b = rand() % (max1 - min1 + 1) + min1;
       if(a == b)
       {
           a = b+1;
       }
       line l;
       l.setl(min(a,b));
       l.setr(max(a,b));
   }
   sort(lines.begin(),lines.end(),comparator);
   return lines;
}


void print(vector<line> lines)
{
    for_each(lines.begin(),lines.end(),[](line l){cout<<l.l<<" ";});
    return;
}

int main()
{
    int max = 10;
    int min = 1;
    int len = 5;
    vector<line> lines = getline(max,min,len);
    print(lines);
    return 0;
}