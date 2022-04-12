#include<iostream>
#include<cstdlib>
using namespace std;

class list//链表的结构
{
public: int value;
  list *next;

  list(int v)
  {
    value = v;
  }
};

//for text
//返回链表的首地址 
list* GetRandomList(int size,int max,int min)//随机生成一个链表
{
  //问题1：由于函数结束后不是动态申请的空间，编译器都会收回（这样生成链表空间收回，函数结束就不能访问了），所以用new动态申请 
  list *head = new list(rand() % (max - min + 1) + min);//生成链表的数值范围在[max,min]
  list *pre = head;
  size--;
  while(size)
  {
    int j = rand() % (max - min + 1) + min;
   // cout<<j<<" ";
    list *cur = new list(j); //动态申请 
    //cout<<cur.value<<" ";
    pre->next = cur;
    pre=pre->next; //问题2：你之前的链表没有链接起来，少了这句 
 
   // head = cur; //头不用变 
    size--;
  }
  pre->next=NULL;
  return head;
}

void print(list *head)//打印整个链表
{
  list *cur = head;
  while(cur)
  {
    cout<<cur->value<<" ";
    cur = cur->next;
  }
  return;
}

int main()
{
  int len = 10;
  int min = 1;
  int max = 10;
  list * dummy = GetRandomList(len,max,min);
  print(dummy);
  return 0;
}