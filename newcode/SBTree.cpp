#include<iostream>
using namespace std;

class SBNode{
    public : int value;
    int key;
    int size;
    SBNode *left,*right;
};

class SBMap{
    SBNode *root;
    int size;
    SBNode leftrotate(SBNode cur)
    {
        SBNode rNode = *cur.right;
        cur.right = rNode.left;
        rNode.left = &cur;
        rNode.size = cur.size;
        cur.size = (cur.left ? cur.left->size : 0) + (cur.right ? cur.right->size : 0) + 1;
        return rNode;
    }

    SBNode rightrotate(SBNode cur)
    {
        SBNode lNode = *cur.left;
        cur.left = lNode.right;
        lNode.right = &cur;
        lNode.size = cur.size;
        cur.size = (cur.left ? cur.left->size : 0) + (cur.right ? cur.right->size : 0) + 1;
        return lNode;
    }

    SBNode maintain(SBNode cur)
    {
        int leftsize = cur.left->size;
        int rightsize = cur.right->size;
        int llsize = cur.left->left->size;
        int lrsize = cur.left->right->size;
        int rlsize = cur.right->left->size;
        int rrsize = cur.right->right->size;
        if(abs(llsize - rightsize) > 1)
        {
            cur = rightrotate(cur);
            cur = maintain(cur);
            cur.right = &maintain(*cur.right);
        }
        else if(abs(lrsize - rightsize) > 1)
        {
            cur.left = &leftrotate(*cur.left);
            cur = rightrotate(cur);
            cur.left = &maintain(*cur.left);
            cur.right = &maintain(*cur.right);
            cur = maintain(cur);
        }
    }

    SBNode add(SBNode nn,SBNode *cur)
    {
         if(cur == NULL)
         {
               return nn;
         }
         if(nn.value > cur->value)
         {
             *cur->right = add(nn,cur->right);
         }
        else if(nn.value < cur->value)
        {
            *cur->left = add(nn,cur->left);
        }
        return maintain(*cur);
    }

    SBNode del(int target,SBNode cur)
    {
         if(target == cur.value)
         {
             
         }
    }
    
};

