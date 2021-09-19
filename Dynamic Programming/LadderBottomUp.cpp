#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long dp[100007]={0};

// Time Complexity: O(n*k)
//Space Complexity: O(n)
void numOfWays(int n,int k)
{
 dp[0]=1;
 for(int i=1;i<n;i++)
 {
  for(int j=1;j<=k;j++)
  {
   if(i-j>=0)
    dp[i]+=dp[i-j];
  }
 }
}

int main()
{
  int n,k;
  cin>>n>>k;
  numOfWays(n,k);
  cout<<dp[n-1]<<endl;
  return 0;
}