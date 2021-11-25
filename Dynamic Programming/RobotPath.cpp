#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll dp[1009][1009];
ll numOfWays(ll n,ll m)
{
 if(dp[0][0]==-1)
  return 0;
 //Computing number of ways for the first row
 REP(j,0,m)
 {
  if(dp[0][j]==-1)
    break;
  dp[0][j]=1;
 }
 //Computing number of ways for the first column
 REP(i,0,n)
 {
  if(dp[i][0]==-1)
    break;
  dp[i][0]=1;
 }
 //Computing number of ways for the rest of the grid
 REP(i,1,n)
 {
  REP(j,1,m)
  {
   if(dp[i][j]==-1)
    continue;
   dp[i][j]=0;
   if(dp[i-1][j]!=-1)
    dp[i][j]=dp[i-1][j]%mod;
   if(dp[i][j-1]!=-1)
    dp[i][j]=((dp[i][j]%mod)+(dp[i][j-1]%mod))%mod;
  }
 }
 if(dp[n-1][m-1]==-1)
  return 0;
 return dp[n-1][m-1];
}

int main()
{
 memset(dp,0,sizeof(dp));
 ll n,m,k;
 cin>>n>>m>>k;
 REP(i,0,k)
 {
  ll row,col;
  cin>>row>>col;
  dp[row-1][col-1]=-1;
 }
 cout<<numOfWays(n,m)<<endl;
 return 0;
}