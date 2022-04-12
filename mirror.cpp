#include <iostream>
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

void mirror(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    Node *cur = head;
    Node *mostright = NULL;
    while(cur)
    {
        mostright = cur->left;
        if(mostright){
        while(mostright != NULL && mostright->right != cur)
        {
            mostright = mostright->right;
        }
        if(mostright->right == NULL)
        {
            mostright->right = cur;
            cur = cur->left;
            continue;
        }
        else{
            mostright->right = NULL;
        }
        }
        cur = cur->right;
    }
}

void pre_and_mirror(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    Node *cur = head;
    Node *mostright = NULL;
    while(cur)
    {
        mostright = cur->left;
        if(mostright){
        while(mostright->right != NULL && mostright->right != cur)
        {
            mostright = mostright->right;
        }
        if(mostright->right == NULL)
        {
            cout<<cur->value;
            mostright->right = cur;
            cur = cur->left;
            continue;
        }
        else{
            mostright->right = NULL;
          }
        }
        else{
            cout<<cur->value;
        }
        cur = cur->right;
    }
}

void in_and_mirror(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    Node *cur = head;
    Node *mostright = NULL;
    while(cur)
    {
        mostright = cur->left;
        if(mostright){
        while(mostright->right != NULL && mostright->right != cur)
        {
            mostright = mostright->right;
        }
        if(mostright->right == NULL)
        {
            mostright->right = cur;
            cur = cur->left;
            continue;
        }
        else{
            mostright->right = NULL;
        }
        
        }
        cout<<cur->value;
        cur = cur->right;
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
   pre_and_mirror(head);
    return 0;
}