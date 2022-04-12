#include <iostream>
#include<queue>
#include<stack>
using namespace std;

class Node//这是二叉树的数据结构
{
public:    int value;
    Node *left;
    Node *right;
    Node(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
    Node(Node* node)
    {
        value = node->value;
        left = node->left;
        right = node->right;
    }
};


void pre(Node *head)//前序遍历，非递归形式
{
    stack<Node> s;
    s.push(*head);
    while(!s.empty())
    {
        Node *cur = new Node(&s.top());
        s.pop();
        cout<<cur->value;
        if(cur->left)s.push(*cur->right);
        if(cur->right)s.push(*cur->left);
    }
    return;
}

void in(Node *head)
{
    if(head!= NULL)
    {
        stack<Node> s;
        Node *cur = head;
        while(!s.empty() || cur)
        { 
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = &s.top();
                cout<<cur->value;
                cur = cur->right;
                s.pop();

            }
        }
    }
} 




void rear(Node *head)
{
   stack<Node> s1;
   stack<Node> s2;
   if(head)
   {
       s1.push(*head);
       while(!s1.empty())
       {
           Node *cur = new Node(&s1.top());
           s2.push(*cur);
           s1.pop();
           if(cur->left) s1.push(*cur->left);
           if(cur->right) s1.push(*cur->right);
       }
       while(!s2.empty())
       {
          cout<<s2.top().value;
          s2.pop();
       }
   }
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