#include<iostream>
#include<string>
using namespace std;
int *getnext(string s)
{
    int cn = 0;
    int i = 2;
    int *next = new int[s.length()];
    while(i  < s.length())
    {
        if(s[i - 1] == s[cn])
        {
            next[i++] = ++cn;
        }
        else if(cn > 0)
        {
            cn = next[cn];
        }
        else{
            next[i++] = 0;
        }
    }
    return next;
}

int kmp(string s1,string s2)
{
    if(s1.length() == 0 || s2.length() == 0 || s2.length() > s1.length())
    {
        return 0;
    }
    int *next = new int[s2.length()];
    next = getnext(s2);
    int i = 0;
    int j = 0;
    while(i < s1.length() && j < s2.length()) {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else if(next[j] > 0)
        {
            j = next[j];
        }
        else{
            j = 0;
        }
    }
    return i > j ? : i - j;
}

