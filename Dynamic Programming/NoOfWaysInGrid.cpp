#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll waysToReachBottomRightCellWithAtmost1StepPerMove(vector<vector<ll>> grid,ll n,ll m)
{
 vector<vector<ll>> dp(n,vector<ll>(m,0));
 REP(i,0,n)
 {
  REP(j,0,m)
  {
   if(i==0||j==0)
   	 dp[i][j]=((grid[i][j])?1:0);
   else
     dp[i][j]=((grid[i][j])?dp[i-1][j]+dp[i][j-1]:0);
  }
 }
 return dp[n-1][m-1];
}

ll waysToReachBottomRightCellWithAtmostKStepPerMove(vector<vector<ll>> grid,ll n,ll m,ll k)
{
 vector<vector<ll>> dp(n,vector<ll>(m,0));
 REP(i,0,n)
 {
  REP(j,0,m)
  {
   if(i==0&&j==0)
   	dp[i][j]=((grid[i][j])?1:0);
   else if(i==0)
   {
    if(grid[i][j])
    {
     for(ll l=1;l<=k&&j-l>=0;l++)
     	dp[i][j]+=dp[i][j-l];
    }
    else
     dp[i][j]=0;
   }
   else if(j==0)
   {
    if(grid[i][j])
    {
     for(ll l=1;l<=k&&i-l>=0;l++)
     	dp[i][j]+=dp[i-l][j];
    }
    else
     dp[i][j]=0;
   }
   else
   {
   	if(grid[i][j])
    {
     for(ll l=1;l<=k&&i-l>=0;l++)
     	dp[i][j]+=dp[i-l][j];
     for(ll l=1;l<=k&&j-l>=0;l++)
     	dp[i][j]+=dp[i][j-l];
    }
    else
     dp[i][j]=0;
   }
  }
 }
 return dp[n-1][m-1];
}


int main()
{
 ll n,m,k;
 cin>>n>>m>>k;
 vector<vector<ll>> grid(n,vector<ll>(m,0));
 REP(i,0,n)
  REP(j,0,m)
   cin>>grid[i][j];
 cout<<"No of ways to reach bottom right cell with atmost 1 step per move: ";
 cout<<waysToReachBottomRightCellWithAtmost1StepPerMove(grid,n,m)<<endl;
 cout<<"No of ways to reach bottom right cell with atmost "<<k<<" step(s) per move: ";
 cout<<waysToReachBottomRightCellWithAtmostKStepPerMove(grid,n,m,k)<<endl;
 return 0;
}