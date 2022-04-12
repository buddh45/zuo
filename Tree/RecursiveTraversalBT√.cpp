#include <iostream>
using namespace std;

class Node
{
public:    int value;
    Node *left;
    Node *right;
    Node(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

void pre(Node *cur)
{
      if(cur == NULL)
      {
          return;
      }
      cout<<cur->value;
      pre(cur->left);
      pre(cur->right);
      return;
}

void in(Node *cur)
{
    if(cur == NULL)
    {
        return;
    }
    in(cur->left);
    cout<<cur->value;
    in(cur->right);
    return;
}

void rear(Node *cur)
{
    if(cur == NULL)
    {
        return;
    }
    rear(cur->left);
    rear(cur->right);
    cout<<cur->value;
    return;
}




int main()
{
   Node *head = new Node(1);
   head->left = new Node(2);
   head->right = new Node(3);
   Node *left = head->left;
   left->left = new Node(4);
   left->right = new Node(5);
   Node *right = head->right;
   right->left = new Node(6);
   right->right = new Node(7);
   rear(head);
    return 0;
}