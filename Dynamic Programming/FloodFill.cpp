#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

//Problem - https://codeforces.com/contest/1114/problem/D

ll minTurnsToUnifyColor(ll a[],ll n)
{
 vector<ll> v;
 v.push_back(a[0]);
 REP(i,1,n)
 {
  while(i<n&&a[i]==a[i-1])
    i++;
  if(i<n)
   v.push_back(a[i]);
 }
 n=v.size();
 vector<vector<ll>> dp(n,vector<ll>(n,0));
 for(ll d=0;d<=n-1;d++)
  {
   for(ll i=0,j=i+d;i<n&&j<n;i++,j++)
   {
    if(j==i)
     dp[i][j]=0;
    else if(j==i+1)
     dp[i][j]=1;
    else if(v[i]==v[j])
     dp[i][j]=1+dp[i+1][j-1];
    else
     dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
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
 cout<<minTurnsToUnifyColor(a,n)<<endl;
 return 0;      
}
