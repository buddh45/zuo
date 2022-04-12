#include <iostream>
using namespace std;

class Node
{
public:     int value;
     Node *next;
     Node(int v):value(v){};
};

Node *findloop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == NULL)
    {
        return NULL;
    }
    fast = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *findjiaodian(Node *head1,int len1,Node *head2,int len2)
{
    Node *max = len1 > len2 ? head1 : head2;
    Node *min = max == head1 ? head2 : head1;
    int dis = abs(len1 - len2);
    while(dis)
    {
        max = max->next;
        dis--;
    }
    while(max != min)
    {
        max = max->next;
        min = min->next;
    }
    return max == NULL ? NULL : max;
}

Node *bothloop(Node *head1,Node *loop1,Node *head2,Node *loop2)
{
    if(loop1 == loop2)
    {
        int n = 0;
        Node *cur1 = head1;
        Node *cur2 = head2;
        while(cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while(cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }
        Node *max = n > 0 ? head1 : head2;
        Node *min = max == head1 ? head2 : head1;
        n = abs(n);
        while(n)
        {
            max = max->next;
            n--;
        }
        while(max != min)
        {
            max = max->next;
            min = min->next;
        }
        return max;
    }
    else{
          Node *cur = loop1->next;
          while(cur != loop1 && cur != loop2)
          {
              cur = cur->next;
          }
          if(cur == loop2)
          {

          }
          else{
              return NULL;

          }
    }
}

int main()
{


    return 0;
}