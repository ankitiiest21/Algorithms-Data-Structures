#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long dp[100007]={0};

// Time Complexity: O(n)
//Space Complexity: O(n)
//Using sliding window approach: dp[i]=dp[i-1]-dp[i-k-1]+dp[i-1]
void numOfWays(int n,int k)
{
 dp[0]=dp[1]=1;
 for(int i=2;i<n;i++)
 {
   dp[i]=2*dp[i-1];
   if(i>k)
    dp[i]-=dp[i-k-1];
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