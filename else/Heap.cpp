#include<iostream>
#include<map>
using namespace std;

class Heap{
public:    int size,*nums,limit;
           map<int,int> hashmap;
    Heap(int l)
    {
        limit = l; 
        nums = new int[l];
        size = 0;
    }

    void push(int n)
    {
        nums[size] = n;
        hashmap[size] = n;
        HeapInsert(size++); 
    } 

    int pop()
    {
        int ans =hashmap[0];
        swap(0,--size);
        hashmap.erase(--hashmap.end());
        Heapify(0);
        return ans;
    }

    bool contains(int index)
    {
         return hashmap.find(index) == hashmap.end() ? false : true;
    }

    int peek()
    {
        return hashmap[0];
    }

    bool isfull()
    {
        return size == limit;
    }

    void swap(int a,int b)
    {
        int a1 = nums[a];
        int b1 = nums[b];
        int tem = nums[a];
        nums[a] = nums[b];
        nums[b] = tem;
        hashmap[b] = a1;
        hashmap[a] = b1;
    }
    void HeapInsert(int index)
    {
        while(comparator(index,(index - 1) / 2) != 0)
        {
            swap(index,(index - 1) / 2);
            index = (index - 1) / 2;
        }
        return;
    }

    
    void Heapify(int index)
    {
        int left = 2 * index + 1;
        while(left < limit)
        {
         int greatest = left + 1 < limit && nums[left + 1] > nums[left] ? left + 1 : left;
         greatest = nums[index] > nums[greatest] ? index : greatest;
                if(greatest == index)
                {
                    break;
                }
            swap(greatest,index);
            index = greatest;
            left = 2 * index + 1;
        }
        return;
    }

    bool comparator(int a,int b)
    {
        return nums[a] < nums[b];
    }

    void show()
    {
        for(int i = 0;i < size;i++)
        {
            cout<<nums[i];
        }
    }
};

int main()
{
     Heap heap(5);
     heap.push(4);
     heap.push(3);
     heap.push(1);
     cout<<heap.pop();
     heap.show();
     return 0;
}