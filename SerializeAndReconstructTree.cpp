#include <iostream>
#include<string>
#include<queue>
#include<algorithm>
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

void ps(Node *cur,queue<string> ans)
{
    if(cur == NULL)
    {
        ans.push("NULL");
    }
    string tem = to_string(cur->value);
    ans.push(tem);
    ps(cur->left,ans);
    ps(cur->right,ans);
}

queue<string> preserialize(Node *cur)
{
      queue<string> ans;
      ps(cur,ans);
      return ans;
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
   queue<string> ans = preserialize(head);
   while(!ans.empty())
   {
       cout<<ans.front();
       ans.pop();
   }
    return 0;
}