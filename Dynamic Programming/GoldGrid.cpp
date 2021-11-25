#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll dp[1007][1007];
ll maxGoldCoinsToBeReceivedBySayan(ll n)
{
 ll ans=LLONG_MIN;
 //For the first row
 REP(j,1,n)
  dp[0][j]=dp[0][j]+dp[0][j-1];
 //For the first column
 REP(i,1,n)
  dp[i][0]=dp[i][0]+dp[i-1][0];
 //For the rest of grid
 REP(i,1,n)
 {
  REP(j,1,n)
   dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
 }
 REP(i,0,n-1)
 {
  REP(j,0,n-1)
  {
   ll part1=dp[i][j];
   ll part2=dp[n-1][j]-dp[i][j];
   ll part3=dp[i][n-1]-dp[i][j];
   ll part4=dp[n-1][n-1]-part1-part2-part3;
   ans=max(ans,min({part1,part2,part3,part4}));
  }
 }
 return ans;
}

int main()
{
 memset(dp,0,sizeof(dp));
 ll n,m,r,c;
 cin>>n>>m;
 REP(i,0,m)
 {
  cin>>r>>c;
  dp[r-1][c-1]=1;
 }
 cout<<maxGoldCoinsToBeReceivedBySayan(n)<<endl;
 return 0;
}