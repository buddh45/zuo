#include <iostream>
#include<string>
using namespace std;

//void hano1()写不出来

void hanoi2(int n,string from,string to,string other)
{
    if(n == 1)
    {
        cout<<"move"<<n<<"from"<<from<<"to"<<to<<endl;
        return;
    }
    hanoi2(n-1,from,other,to);
    cout<<"move"<<n<<"from"<<from<<"to"<<to<<endl;
    hanoi2(n-1,to,other,from);
}

int main()
{
   hanoi2(3,"左","中","右");
    return 0;
}