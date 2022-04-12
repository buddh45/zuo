#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Node
{
    public : bool isend;
     string endUse;
     Node *fail;
     Node *next;
     Node()
     {
         isend = false;
         fail = NULL;
         next = new Node[26];
     }
     
     
};

class AcAutomation{
    Node *root;


    void insert(string s)
    {
        Node *cur = root;
        for(int i = 0;i < s.length();i++)
        {
            int index = s[i] - 'a';
            if(cur->next[index].next == NULL)
            {
                Node next;
                cur->next = &next;
            }
            cur = cur->next;
        }
        cur->endUse = s;
    }
    
    void build()
    {
      queue<Node> q;
      q.push(*root);
      while(!q.empty())
      {
          Node cur = q.front();
          q.pop();
          for(int i = 0;i < 26;i++){
                if(cur.next)
                {

                }
          }
      }
    }
};

