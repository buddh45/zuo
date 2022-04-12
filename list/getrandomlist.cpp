#include <iostream>
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
    return 0;
}