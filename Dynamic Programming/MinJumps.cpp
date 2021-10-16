#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll minJumpsToReachLastIndex(ll a[],ll n)
{
 ll*dp=new ll[n];
 ll mini=INT_MAX;
 REPI(i,0,n)
 {
  if(i==n-1)
   dp[i]=0;
  else if(a[i]==0)
  	dp[i]=999999999;
  else if(i+a[i]>=n-1)
   dp[i]=1;
  else
  {
   ll temp=999999999;
   REP(j,i+1,i+a[i]+1)
    temp=min(temp,dp[j]);
   dp[i]=1+temp;
  }
 }
 // REP(i,0,n)
 //  cout<<dp[i]<<" ";
 // cout<<endl;
 return dp[0];
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<minJumpsToReachLastIndex(a,n)<<endl;
 return 0;
}