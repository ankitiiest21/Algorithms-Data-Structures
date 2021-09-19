// Problem link- https://hack.codingblocks.com/app/contests/1310/546/problem
#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;

long long minCostToGenerateNCells(int n,int x,int y,int z)
{
 long long*dp=new long long[n+1];
 dp[0]=dp[1]=0;
 for(int i=2;i<=n;i++)
 {
  if(i%2==0)
   dp[i]=min(dp[i/2]+x,dp[i-1]+y);
  else
   dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
 }
 return dp[n];
}

int main()
{
  int n,x,y,z;
  cin>>n>>x>>y>>z;
  cout<<minCostToGenerateNCells(n,x,y,z)<<endl;
  return 0;
}