#include<bits/stdc++.h>
#include<iostream>
long long dp[100007]={0};
using namespace std;

long long minStepToOne(int n)
{
 dp[1]=0;
 for(int i=2;i<=n;i++)
 {
  long long ans=INT_MAX;
  if(i%3==0)
   ans=min(ans,dp[i/3]+1);
  if(i%2==0)
   ans=min(ans,dp[i/2]+1);
  ans=min(ans,dp[i-1]+1);
  dp[i]=ans; 
 }
 return dp[n];
}

int main()
{
 int n;
 cin>>n;
 cout<<minStepToOne(n)<<endl;
 return 0;
}