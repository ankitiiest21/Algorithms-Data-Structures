#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll maxScore(ll a[],ll n)
{
 map<ll,ll> mp;
 ll maxi=INT_MIN;
 REP(i,0,n)
  mp[a[i]]++,maxi=max(maxi,a[i]);
 ll*dp=new ll[maxi+1];
 dp[0]=0;
 dp[1]=mp[1];
 REP(i,2,maxi+1)
  dp[i]=max(i*mp[i]+dp[i-2],dp[i-1]);
 return dp[maxi];
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<maxScore(a,n)<<endl;
 return 0;
}