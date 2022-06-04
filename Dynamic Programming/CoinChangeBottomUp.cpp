#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
long long dp[10007][100]={0};

using namespace std;

long long numberOfWays(int n,int m,int coins[])
{
 for(int j=0;j<m;j++)
  dp[0][j]=1;
 for(int i=1;i<n+1;i++)
 {
  for(int j=1;j<m+1;j++)
  {
   if(i>=coins[j-1])
    dp[i][j]=dp[i-coins[j-1]][j];
   dp[i][j]+=dp[i][j-1];
  }
 }
 return dp[n][m];
}

int main()
{
  int n,m;
  cin>>n>>m;
  int coins[m];
  for(int i=0;i<m;i++)
   cin>>coins[i];
  cout<<numberOfWays(n,m,coins)<<endl;
 return 0;
}
