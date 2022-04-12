#include <iostream>
#include<map>
using namespace std;

class Node
{
public: int value;
    Node *next;
    Node *randnext;
    Node() = default;
    Node(int v):value(v){};
};

Node *copy1(Node *head)
{
    map<Node,Node> hashmap;
    Node *cur = head;
    while(cur != NULL)
    {
        hashmap[*cur] = Node(cur->value);
        cur = cur->next;
    }
    cur = head;
    Node *newNode = NULL;
    while(cur != NULL)
    {
        newNode = &hashmap[*cur];
        newNode->next = &hashmap[*(cur->next)];
        newNode->randnext = &hashmap[*(cur->randnext)];
        cur = cur->next;
    }
    return &hashmap[*head];
}

Node *copy2(Node *head)
{
    Node *cur = head;
    while(cur != NULL)
    {
        Node *next = cur->next;
        Node *newNode = new Node(head->value);
        cur->next = newNode;
        newNode->next = next;
        cur = next;
    }
    cur = head;
    while(cur != NULL)
    {
        Node *next = cur->next->next;
        cur->next->next = next->next;
        cur->next->randnext = cur->randnext->next;
    }
    return cur->next;
}




int main()
{


    return 0;
}