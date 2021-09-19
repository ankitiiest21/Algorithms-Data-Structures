#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long dp[100007];

long long maxSumSubarray(long long a[],int n)
{
 dp[0]=a[0];
 long long max_so_far=dp[0];
 for(int i=1;i<n;i++)
 {
  dp[i]=max(a[i],dp[i-1]+a[i]);
  max_so_far=max(max_so_far,dp[i]);
 }
 return max_so_far;
}

//Space Optimised approach
long long maxSumSubarraySpaceOptimised(long long a[],int n)
{
 long long current_max=a[0];
 long long max_so_far=a[0];
 for(int i=1;i<n;i++)
 {
  current_max=max(a[i],current_max+a[i]);
  max_so_far=max(max_so_far,current_max);
 }
 return max_so_far;
}

int main()
{
  int n;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];
  cout<<maxSumSubarray(a,n)<<endl;
  cout<<maxSumSubarraySpaceOptimised(a,n)<<endl;
  return 0;
}