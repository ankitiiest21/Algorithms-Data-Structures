#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

string findSubsetSumEqualToTarget(ll a[],ll n,ll sum)
{
 vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
 REP(i,0,n+1)
  dp[i][0]=true;
 REP(j,1,sum+1)
 {
  REP(i,1,n+1)
  {
   if(a[i-1]<=j)
    dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
   else
    dp[i][j]=dp[i-1][j];
  }
 }
 if(dp[n][sum]) 
    return "Yes";
 else 
    return "No";
}

int main()
{
 ll n,sum;
 cin>>n>>sum;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<findSubsetSumEqualToTarget(a,n,sum)<<endl;
 return 0;
}