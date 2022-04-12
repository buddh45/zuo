#include <iostream>
using namespace std;

int f(int N,int cur,int rest,int aim)
{
      if(rest == 0)
      {
          cur == aim ? 1 : 0;
      }
      int ans = 0;
      if(cur == 1)
      {
        ans = f(N,++cur,rest - 1,aim);
      }
      else if(cur == N)
      {
           ans = f(N,++cur,rest-1,aim);
      }
      else{
         ans = f(N,++cur,rest-1,aim) + f(N,--cur,rest-1,aim);
      }
      return ans;
}



int process1(int N,int cur,int rest,int aim)
{
     int ans = f(N,cur,rest,aim);
     return ans;
}
int g1(int N,int cur,int rest,int aim,int *dp[])
{
    if(rest == 0)
    {
        return cur == aim ? 1 : 0;
    }
    if(cur == 0)
    {
        dp[cur + 1][rest-1] = g1(N,++cur,--rest,aim,dp);
    }
    else if(cur == N)
    {
        dp[cur -1][rest-1] = g1(N,--cur,--rest,aim,dp);
    }
    else{
        dp[cur][rest] = g1(N,--cur,--rest,aim,dp) + g1(N,++cur,--rest,aim,dp);
    }
    return;
}

int prcocess2(int N,int cur,int rest,int aim)
{
      int **dp = new int*[N + 1];
      for(int i = 0;i <= N;i++)
      {
          dp[i] = new int[rest + 1];
      }
     g1(N,cur,rest,aim,dp);
     int ans =  dp[cur][rest];
     return ans;
}

int prcocess3(int N,int cur,int rest,int aim)
{
    int **dp = new int*[rest + 1];
      for(int i = 0;i <= rest;i++)
      {
          dp[i] = new int[N + 1];
      } 
      dp[0][aim] = 1;
      for(int i = 1;i < N;i++)
      {
           dp[i][1] = dp[i-1][2];
           for(int j = 2;j <= N;j++)
           {
               dp[i][j] = dp[i-1][j-1] + dp[i-1][j + 1];
           }
      }
      return dp[rest][aim];
}

int main()
{


    return 0;
}