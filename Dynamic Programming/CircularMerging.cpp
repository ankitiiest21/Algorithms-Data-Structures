#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll prefixSum[100008];

ll findSum(ll l,ll r,ll n)
{
 if(l<=r)
  return prefixSum[r]-((l==0)?0:prefixSum[l-1]);
 return prefixSum[n-1]-prefixSum[l-1]+prefixSum[r];
}

ll minPenaltyToMergeCircularArray(ll a[],ll n)
{
 ll dp[n][n];
 prefixSum[0]=a[0];
 REP(i,1,n)
  prefixSum[i]=prefixSum[i-1]+a[i];
 REP(i,0,n)
 {
  REP(j,0,n)
  {
   if(i==j)
    dp[i][j]=0;
   else
    dp[i][j]=LLONG_MAX;
  }
 }

 REP(size,2,n+1)
 {
  REP(i,0,n)
  {
   ll l=i,r=(i+size-1)%n;
   for(ll j=l;j!=r;j=(j+1)%n)
   {
    dp[l][r]=min(dp[l][r],dp[l][j]+dp[(j+1)%n][r]+findSum(l,r,n));
   }
  }
 }
 ll ans=LLONG_MAX;
 REP(i,0,n)
 {
  ll l=i,r=(i-1+n)%n;
  ans=min(ans,dp[l][r]);
 }
 return ans;
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<minPenaltyToMergeCircularArray(a,n)<<endl;
 return 0;
}