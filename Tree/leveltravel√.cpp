#include <iostream>
#include<queue>
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
        Node *newnode = new Node(node->value);
        newnode->left = new Node(node->left->value);
        newnode->right = new Node(node->right->value);
    }
};

void leveltraverse(Node *head)
{
    queue<Node> q;
    q.push(*head);
    
    while(!q.empty())
    {
        Node cur = q.front();
        cout<<cur.value;
        q.pop();
        if(cur.left){
        q.push(*cur.left);
        }
        if(cur.right){
        q.push(*cur.right);
        }
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
   leveltraverse(head);
    return 0;
}