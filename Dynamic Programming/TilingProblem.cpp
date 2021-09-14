#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007

using namespace std;

long long numberOfWays(int n,int m)
{
 long long dp[n+1]={0};
 for(int i=0;i<n+1;i++)
 {
  if(i<m)
   dp[i]=1;
  else if(i==m)
   dp[i]=2;
  else 
   dp[i]=((dp[i-1]%mod)+(dp[i-m]%mod))%mod;
 }
 return dp[n]%mod;
}

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,m;
  cin>>n>>m;
  cout<<numberOfWays(n,m)<<endl;
 }
 return 0;
}