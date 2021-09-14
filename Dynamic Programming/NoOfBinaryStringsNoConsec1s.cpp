#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007

using namespace std;

long long numberOfBinaryStrings(int n)
{
 long long dp[n][2]={0};
 dp[0][0]=dp[0][1]=1;
 for(int i=1;i<n;i++)
 {
  dp[i][0]=dp[i-1][0]+dp[i-1][1];
  dp[i][1]=dp[i-1][0];
 }
 return dp[n-1][0]+dp[n-1][1];
}

long long numberOfBinaryStringsUsingFibonacci(int n)
{
 //While carefully observing the pattern, we can deduce that it follows a fibonacci pattern with a0=2,a1=3
 long long a0=2,a1=3,ai;
 if(n==1)
  return a0;
 if(n==2)
  return a1;
 for(int i=3;i<=n;i++)
 {
  ai=a0+a1;
  a0=a1;
  a1=ai;
 }
 return ai;
}

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  cout<<numberOfBinaryStrings(n)<<endl;
  cout<<numberOfBinaryStringsUsingFibonacci(n)<<endl;
 }
 return 0;
}