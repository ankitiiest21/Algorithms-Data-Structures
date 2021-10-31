#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll minOperationsToMakeStringSame(string a,string b)
{
 ll n=a.size(),m=b.size();
 vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
 REP(i,0,n+1)
 {
  REP(j,0,m+1) 
  {
   if(i==0)
   	dp[i][j]=j;
   else if(j==0)
   	dp[i][j]=i;
   else if(a[i-1]==b[j-1])
   	dp[i][j]=dp[i-1][j-1];
   else
   	dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
  }
 }
 return dp[n][m];
}

int main()
{
 string a,b;
 cin>>a>>b;
 cout<<minOperationsToMakeStringSame(a,b)<<endl;
 return 0;
}