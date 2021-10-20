#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll optimalStrategyOfGame(ll a[], ll n)
{
  ll dp[n][n];
  memset(dp,0,sizeof(dp));
  for(ll d=0;d<n;d++)
  {
   for(ll i=n-1-d;i>=0;i--)
   {
    ll j=i+d;
    if(i==j)
      dp[i][j]=a[i];
    else if(j==i+1)
       dp[i][j]=max(a[i],a[j]);
    else
       dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
   }
  }
   return dp[0][n-1];
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<optimalStrategyOfGame(a,n)<<endl;
 return 0;
}