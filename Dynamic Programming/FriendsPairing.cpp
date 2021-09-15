#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007

using namespace std;

long long numberOfWays(int n)
{
 long long dp[n+1]={0};
 dp[1]=1;
 dp[2]=2;
 for(int i=3;i<=n;i++)
 //dp[i-1] when ith person remains single
 //we can pair ith person with any of the remaining (i-1) person and multiply it with remaining person's answer-dp[i-2] 
  dp[i]=dp[i-1]+(i-1)*dp[i-2];  
 return dp[n];
}

int main()
{
 int t=1;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  cout<<numberOfWays(n)<<endl;
 }
 return 0;
}