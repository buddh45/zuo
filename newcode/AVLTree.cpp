#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//左旋，右旋，删除，增加，查找最后一个结点和第一个结点

class AVLNode
{
    public : int value;
    int height;
    AVLNode *left,*right;
    AVLNode(int v){
        value = v;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLMap
{
    public : int size = 0;
    AVLNode *root;

    AVLNode leftrotate(AVLNode *Node)
    {
        AVLNode right = *Node->right;
        Node->right = right.left;
        right.left = Node;
        
        Node->height = max((Node->left)->height,Node->right->height) + 1;
        right.height = max(right.left->height,right.right->height) + 1;
        return right;
    }

    AVLNode rightrotate(AVLNode *Node)
    {
        AVLNode l = *Node->left;
        Node->left = l.right;
        l.right = Node;
        Node->height = max((Node->left)->height,Node->right->height) + 1;
        l.height = max(l.left->height,l.right->height) + 1;
        return l;
    }

    AVLNode matatian(AVLNode *cur){
        int l = cur ? cur->left->height : 0;
        int r = cur ? cur->right->height : 0;
        AVLNode res;
        if(abs(l - r) > 1)
        {
            
            if(l > r){
                int ln = cur->left->left->height;
                int rn = cur->left->right->height;
                if(l > r)
                {
                    res = rightrotate(cur);
                }
                else{
                    AVLNode r = leftrotate(cur);
                     res = rightrotate(&r);
                }
            }
        }
        return res;
    }

    AVLNode add(AVLNode Node,AVLNode cur)
    {
        if(Node.value > cur.value)
        {
            *cur.right = add(Node,*cur.right);
        }
        else if(Node.value < cur.value){
               *cur.left = add(Node,*cur.left);
        }
        cur.height = max(cur.left->height,cur.right->height) + 1;
        matatian(&cur);
        return cur;
    }

    void del(AVLNode Node,AVLNode cur)
    {
        if(cur.value > Node.value)
        {
            del(Node,*cur.left);
        }
        else if(cur.value < Node.value)
        {
             del(Node,*cur.right);
        }
        else{
            if(cur.left == NULL)
            {
                
            }
            AVLNode *rightmostleft = Node.right;
            while(rightmostleft)
            {
                rightmostleft = Node.left;
            }

        }
    }
};

