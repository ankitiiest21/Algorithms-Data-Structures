#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long long minCoinChange(int coins[],int n,int sum)
{
 long long ans=INT_MAX;
 if(sum==0)
  return 0;
 for(int i=0;i<n;i++)
  if(coins[i]<=sum)
   ans=min(ans,minCoinChange(coins,n,sum-coins[i])+1);
  return ans;
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