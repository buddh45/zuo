#include <iostream>
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


Node *getmid(Node *head)
{
   Node *slow = head;
   Node *fast = head;
   while(fast->next != NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow;
}

Node *getmidpre(Node *head)
{
   Node *slow = head;
   Node *fast = head->next->next;
   while(fast->next != NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow;
}

Node *getmidnext(Node *head)
{
   Node *slow = head->next;
   Node *fast = head;
   while(fast->next != NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow;
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

int main()
{
    Node *head = new Node('a');
    head->push('c');
    Node *next = head->next;
   next->push('e');
   next = next->next;
   next->push('c');
   next = next->next;
   next->push('a');
   print(head);
   Node *mid = getmidpre(head);
   cout<<mid->value;
    return 0;
}