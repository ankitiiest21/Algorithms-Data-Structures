#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;
 
//0th index for even,1th index for odd 
ll dp[200009][2];

void numOfPairsHavingOddSum(ll l[],ll r[],ll n)
{
 if(l[0]%2==1)
 {
  if(r[0]%2==1)
  	dp[0][0]=0,dp[0][1]=2;
  else
  	dp[0][0]=1,dp[0][1]=1;
 }
 else
 {
  if(r[0]%2==1)
  	dp[0][0]=1,dp[0][1]=1;
  else
  	dp[0][0]=2,dp[0][1]=0;
 }

 REP(i,1,n)
 {
  if(l[i]%2)
  {
   if(r[i]%2)
   	dp[i][0]=((dp[i-1][1]%mod)*2)%mod,dp[i][1]=((dp[i-1][0]%mod)*2)%mod;
   else
   	dp[i][0]=dp[i][1]=((dp[i-1][0]%mod)+(dp[i-1][1]%mod))%mod;
  }
  else
  {
   if(r[i]%2)
   	dp[i][0]=dp[i][1]=((dp[i-1][0]%mod)+(dp[i-1][1]%mod))%mod;
   else
   	dp[i][0]=((dp[i-1][0]%mod)*2)%mod,dp[i][1]=((dp[i-1][1]%mod)*2)%mod;
  }
 }
}

int main()
{
 ll n;
 cin>>n;
 ll l[n],r[n];
 REP(i,0,n)
  cin>>l[i]>>r[i];
 numOfPairsHavingOddSum(l,r,n);
 cout<<dp[n-1][1]<<endl;
}