#include<iostream>
using namespace std;


class Node{
public:    int value;
    Node *left,*right;
    void set(int v,Node l,Node r)
    {
       value = v;
       left = &l;
       right = &r;
    }
};

void mirror(Node *root)
{
     Node *mostright,*cur;
     cur = root;
     while(cur != NULL)
     {
        cur = cur->left;
         mostright = cur->left;
         while(mostright != NULL)
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
         cur = cur->right;
     }
}

