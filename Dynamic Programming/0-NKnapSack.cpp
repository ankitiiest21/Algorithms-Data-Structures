#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll maxValueWithinCapacity(ll size[],ll val[],ll n,ll s)
{
 vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
 REP(i,1,n+1)
 {
  REP(j,1,s+1)
  {
   if(j-size[i-1]>=0)
   	dp[i][j]=max(val[i-1]+max(dp[i-1][j-size[i-1]],dp[i][j-size[i-1]]),dp[i-1][j]);
   else
   	dp[i][j]=dp[i-1][j];
  }
 }
 return dp[n][s];
}

int main()
{
 ll n,s;
 cin>>n>>s;
 ll size[n],val[n];
 REP(i,0,n)
  cin>>size[i];
 REP(i,0,n)
  cin>>val[i];
 cout<<maxValueWithinCapacity(size,val,n,s)<<endl;
 return 0;
}