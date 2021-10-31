#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

bool wildcardPatternMatching(string s,string pat)
{
 ll n=s.size(),m=pat.size();
 vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
 dp[0][0]=true;
 REP(j,1,m+1)
  dp[0][j]=((pat[j-1]=='*')?dp[0][j-1]:false);
 REP(i,1,n+1)
 {
  REP(j,1,m+1)
  {
   if(s[i-1]==pat[j-1])
    dp[i][j]=dp[i-1][j-1];
   else if(pat[j-1]=='*')
    dp[i][j]=dp[i][j-1]||dp[i-1][j];
   else if(pat[j-1]=='?')
    dp[i][j]=dp[i-1][j-1];
   else
    dp[i][j]=false;
  }
 }
 return dp[n][m];
}

int main()
{
 string s,pat;
 cin>>s>>pat;
 cout<<((wildcardPatternMatching(s,pat)?"1":"0"))<<endl;
 return 0;
}