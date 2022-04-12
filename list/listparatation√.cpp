#include <iostream>
#include<stack>
#include<cstdlib>
using namespace std;

class Node
{
public:    int value;
    Node *next;
    Node() = default;
    Node(int v){
        value = v;
        next = NULL;
    }

    void push(int v)
    {
        next = new Node(v);
    }
};


Node *paratation1(Node *head,int v)
{
    stack<Node> min;
    stack<Node> equ;
    stack<Node> max;
    while(head != NULL)
    {
        int value = head->value;
        if(value == v)
        {
            equ.push(*head);
        }
        else if(value > v)
        {
            max.push(*head);
        }
        else{
            min.push(*head);
        }
        head = head->next;
    }
    Node *dummy = new Node(min.top());
    Node *cur = dummy;
    min.pop();
    while(!min.empty())
    {
        dummy->next = new Node(min.top().value);
        min.pop();
        dummy = dummy->next;
    }
    while(!equ.empty())
    {
       dummy->next = new Node(equ.top().value);
        equ.pop();
        dummy = dummy->next;
    }

    while(!max.empty())
    {
         dummy->next = new Node(max.top().value);
        max.pop();
        dummy = dummy->next;
    }
    return cur;
}

Node *paratation2(Node *head,int v)
{
    Node *minhead = NULL;
    Node *maxhead = NULL;
    Node *equhead = NULL;
    Node *mintail = NULL;
    Node *maxtail = NULL;
    Node *equtail = NULL;
    Node *cur = head;
    while(cur != NULL)
    {
        if(v == cur->value)
         {
             if(equhead == NULL)
             {
                 equhead = equtail = new Node(cur->value);
             }
             else{
                 equtail->next = new Node(cur->value);
                 equtail = head;
             }
         }
         else if(v < cur->value)
         {
             if(maxhead == NULL)
             {
                 maxhead = maxtail = new Node(cur->value);
             }
             else{
                 maxtail->next = new Node(cur->value);
                 maxtail = maxtail->next;
             }
         }
         else{
             if(minhead == NULL)
             {
                 minhead = mintail = new Node(cur->value);
             }
             else{
                 mintail->next = new Node(cur->value);
                 mintail = mintail->next;
             }
         }
         cur = cur->next;
    }
    if(minhead != NULL)
    {
        mintail->next = equhead;
        equtail = equtail == NULL ? maxtail : equtail;
    }
    if(equhead != NULL)
    {
        equtail->next = maxhead;
    }
    return minhead == NULL ? (equhead == NULL ? maxhead : equhead) : minhead;
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

int main()
{
   int max = 10;
   int min = 1;
   int len = 5;
   Node *head = getrandomlist(max,min,len);
   print(head);
   Node *head1 = paratation2(head,5);
    print(head1);
    return 0;
}