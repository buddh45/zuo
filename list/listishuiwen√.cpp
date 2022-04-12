#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:    char value;
    Node *next;
    Node() = default;
    Node(char v){
        value = v;
        next = NULL;
    }

    void push(char v)
    {
        next = new Node(v);
    }
};




bool ishuiwen1(Node *head)
{
   stack<Node> s;
   Node *cur = head;
   while(cur != NULL)
   {
       s.push(*cur);
       cur = cur->next;
   }
   cur = head;
   while(!s.empty())
   {
       if(cur->value == s.top().value)
       {
           cur = cur->next;
           s.pop();
       }
       else{
           return false;
       }
   }
   return true;
}

Node *reverlist2(Node *head)
{
      Node *pre = NULL;
      Node *next = NULL;
      Node *cur = head;
      while(cur != NULL)
      {
         next = cur->next;
          cur->next = pre;
          pre = cur;
          cur = next;
          
      }
      return pre;
}
bool ishuiwen2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    stack<Node> s;
    while(slow != NULL)
    {
        s.push(*slow);
        slow = slow->next;
    }
    while(!s.empty())
    {
        if(head->value == s.top().value)
        {
            s.pop();
            head = head->next;
        }
        else{
            return false;
        }
    }
    return true;
}

bool ishuiwen3(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *cur = reverlist2(slow);
    while(cur != NULL)
    {
        if(head->value == cur->value)
        {
             cur = cur->next;
             head = head->next;
        }
        else{
            return false;
        }
    }
    return true;
}



int main()
{
    Node *head = new Node('a');
    head->push('c');
    Node *cur = head->next;
    cur->push('c');
    cur = cur->next;
    cur->push('a');
    cout<<ishuiwen2(head);
    return 0;
}