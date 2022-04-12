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
    Node(Node *node)
    {
     //应该像下面这样写 
        value = node->value;
        left = node->left;
        right = node->right;
       
     /*Node *newnode = new Node(node->value);
        newnode->left = new Node(node->left->value);
        newnode->right = new Node(node->right->value);*/
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
        
        cout<<cur->value<<" ";
        if(cur->right!=NULL)s.push(*cur->right); //这里加个条件判断，否则会出错 
        if(cur->left!=NULL)s.push(*cur->left);        
    }
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
   pre(head);
    return 0;
}