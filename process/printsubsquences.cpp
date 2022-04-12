#include <iostream>
#include<set>
#include<string>
#include<list>
using namespace std;

void PrintAllSubsquences(string s,int index,list<string> ans,string path)
{
    if(index == s.length())
    {
        ans.push_back(path);
        return;
    }
    PrintAllSubsquences(s,index+1,ans,path);
    PrintAllSubsquences(s,index++,ans,path + s[index]);
}

void SubNoRepeat(string s)
{
    set<string> hashset;
    process(s,0,hashset,"");
    list<string> ans;
    for(string str : hashset)
    {
        ans.push_back(str);
    }
    return;
}

void process(string s,int index,set<string> hashset,string path)
{
    if(index == s.length())
    {
       hashset.insert(path);
       return;
    }
    process(s,index+1,hashset,path);
    process(s,index++,hashset,path +s[index]);
}






list<string> f1(string rest,string path,list<string> ans)
{
    if(rest.empty())
    {
        ans.push_back(path);
    }
    else{
        
     for(int i = 0;i < rest.length();i++)
     {
         char c = rest[i];
         rest.erase(rest.begin() + i);
         f1(rest,path + c,ans);
         rest.insert(rest.begin() + i,c);
     }
    }
    return ans;
}

list<string> permutation(string s)
{
     list<string> ans;
     string path = "";
     f1(s,path,ans);
     return ans;
}

void swap(string s,int a,int b)
{
    char tem = s[a];
    s[a] = s[b];
    s[b] = tem;
    return;
}

void process(string s,int index,list<string> ans)
{
    if(index == s.length())
    {
        ans.push_back(s);
    }
    for(int i = index;i < s.size();i++)
    {
         swap(s,index,i);
         process(s,index+1,ans);
         swap(s,index,i);
    }
    return;
}

void f2(string s,int index,list<string> ans)
{
      if(index == s.size())
      {
          ans.push_back(s);
      }
      bool *visited = new bool[256];
      for(int i = index;i < s.length();i++)
      {
         if(!visited[s[i]])
         {
             visited[s[i]] = true;
             swap(s,index,i);
             f2(s,index+1,ans);
             swap(s,index,i);
         }
      }
      return;
}

list<string> permutation1(string s)
{
    list<string> ans;
    f2(s,0,ans);
    return ans;
}

int main()
{


    return 0;
}