#include<iostream>
#include<cstdlib>
using namespace std;


class Node{
 public :    int value;
    Node *pre;
    Node *next;

    Node(int v)
    {
        value = v;
    }
};


class StackAndqueue{
    Node *head;
    Node *tail;
    
  

    void addfrombottom(int v)
    {
        Node cur = Node(v);
        if(tail == NULL)
        {

            head = &cur;
            tail = &cur;
        }
        else{
            Node tem = cur;
            cur = *tail;
            *tail = tem;
        }
    }

    void addfromhead(int v)
    {
        Node cur = Node(v);
        if(head == NULL)
        {
            head = &cur;
            tail = &cur;
        }
        else{
            Node tem = cur;
            cur = *head;
            *head = tem;
        }
    }

    Node popfrombottom()
    {
        if(tail == NULL)
        {
            return NULL;
        } 
        Node ans = *tail;
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else{
           tail = tail->pre;
           tail->next = NULL;
           ans.pre = NULL;
        }
    }
};

class Myqueue
{
      StackAndqueue queue;
      
};