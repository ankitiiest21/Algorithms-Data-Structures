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
  for(int j=0;j<m;j++)
  {
   if(i>=coins[j])
    dp[i][j]=dp[i-coins[j]][j];
   dp[i][j]+=dp[i][j-1];
  }
 }
 return dp[n][m-1];
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