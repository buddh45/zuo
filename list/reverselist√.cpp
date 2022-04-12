#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:    int value;
    Node *next;
    Node() = default;
    Node(int v){
        value = v;
        next = NULL;
    };
};

Node *reverselist1(Node *head)
{
    stack<Node> s;
    Node *cur = head;
    Node *help = NULL;
    while(cur != NULL)
    {
        s.push(*cur);
        cur = cur->next;
    }
    Node *dummy = new Node(s.top().value);
    cur = dummy;
    s.pop();
    while(!s.empty())
    {
        cur->next = new Node(s.top().value);
        cur = cur->next;
        s.pop();
    }
    cur->next = NULL;
    return dummy;
}


Node *getrandomlist(int max,int min,int len)
{
    Node *cur = new Node(rand() % (max - min + 1) + min);
    len--;
    Node *head = cur;
    while(len)
    {
       cur->next = new Node(rand() % (max - min + 1) + min);
       cur = cur->next;
       len--;
    }
    return head;
}

void print(Node *head)
{
    Node *cur = head;
    while(cur != NULL)
    {
        cout<<cur->value<<" ";
        cur = cur->next;
    }
    cout<<endl;
    return;
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

int main()
{
    Node *head = getrandomlist(10,1,5);
    print(head);
    Node *head1 = reverlist2(head);
    print(head1);
    return 0;
}