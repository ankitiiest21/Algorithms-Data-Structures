#include<bits/stdc++.h>
#include<iostream>
long long dp[1000007]={INT_MAX};

using namespace std;

long long minCoinChange(int coins[],int n,int sum)
{
 dp[0]=0;

 for(int i=1;i<=sum;i++)
 {
  dp[i]=INT_MAX;
  for(int j=0;j<n;j++)
  {
   if(coins[j]<=i)
    dp[i]=min(dp[i],dp[i-coins[j]]+1);
  }
 }
 return dp[sum];
}

int main()
{
 int n,sum;
 cin>>n>>sum;
 int coins[n];
 for(int i=0;i<n;i++)
  cin>>coins[i];
 cout<<minCoinChange(coins,n,sum)<<endl;
 return 0;
}