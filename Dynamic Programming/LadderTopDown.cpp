#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long dp[100007]={0};

// Time Complexity: O(n*k)
//Space Complexity: O(n)
long long numOfWays(int n,int k)
{
 if(n==0)
  return 1;
 if(dp[n-1]!=0)
  return dp[n-1];
 long long ans=0;
 for(int i=1;i<=k;i++)
 {
  if(n-i>=0)
   ans+=numOfWays(n-i,k);
 }
 return dp[n-1]=ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  n--;
  cout<<numOfWays(n,k)<<endl;
  return 0;
}