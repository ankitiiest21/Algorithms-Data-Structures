#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;


string lcs(string a,string b)
{
 ll n=a.size(),m=b.size();
 string LCS;
 vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
 REP(i,1,n+1)
 {
  REP(j,1,m+1)
  {
   if(a[i-1]==b[j-1])
   	dp[i][j]=1+dp[i-1][j-1];
   else
   	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  }
 }
 ll l=n,r=m;
 while(l>0&&r>0)
 {
  if(a[l-1]==b[r-1])
   LCS+=a[l-1],l--,r--;
  else if(dp[l][r]==dp[l-1][r])
  	l--;
  else
  	r--;
 }
 reverse(LCS.begin(), LCS.end());
 return LCS;
}

int main()
{
 string s1,s2;
 cin>>s1>>s2;
 cout<<lcs(s1,s2)<<endl;
 return 0;
}