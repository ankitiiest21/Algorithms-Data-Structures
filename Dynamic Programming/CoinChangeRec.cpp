#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007

using namespace std;

long long numberOfWays(int n,int m,int coins[])
{
 if(n==0)
  return 1;
 if(m==0)
  return 0;
 long long ans=0;
 if(coins[m-1]<=n)
  ans=numberOfWays(n-coins[m-1],m,coins);
 ans+=numberOfWays(n,m-1,coins);
 return ans;
}

int main()
{
 int t=1;
//  cin>>t;
 while(t--)
 {
  int n,m;
  cin>>n>>m;
  int coins[m];
  for(int i=0;i<m;i++)
   cin>>coins[i];
  cout<<numberOfWays(n,m,coins)<<endl;
 }
 return 0;
}