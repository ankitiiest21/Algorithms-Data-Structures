#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll maxSideLengthSquareMatrixOfAllOnes(vector<vector<ll>> mat)
{
 ll n=mat.size(),m=mat[0].size();
 vector<vector<ll>> dp(n,vector<ll>(m,0));
 REP(i,0,n)
 {
  if(mat[i][0]==1)
  	dp[i][0]=1;
  else
  	dp[i][0]=0;
 }
 REP(j,0,m)
 {
  if(mat[0][j]==1)
  	dp[0][j]=1;
  else
  	dp[0][j]=0;
 }
 REP(i,1,n)
 {
  REP(j,1,m)
  {
   if(mat[i][j])
   	dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
   else
   	dp[i][j]=0;
  }
 }
 ll ans=LLONG_MIN;
 REP(i,0,n)
 {
  REP(j,0,m)
   ans=max(ans,dp[i][j]);
 }
 return ans;
}

int main()
{
 ll n,m;
 cin>>n>>m;
 vector<vector<ll>> mat(n,vector<ll>(m,0));
 REP(i,0,n)
 {
  REP(j,0,m)
   cin>>mat[i][j];
 }
 cout<<maxSideLengthSquareMatrixOfAllOnes(mat)<<endl;
 return 0;
}