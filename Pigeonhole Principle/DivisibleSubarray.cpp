// https://hack.codingblocks.com/app/practice/6/1065/problem
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n,a,sum=0,ans=0;
  cin>>n;
  vector<ll> pre(n+1,0);
  pre[0]=1;
  REP(i,0,n)
  {
   cin>>a;
   sum+=a;
   sum%=n;
   sum=(sum+n)%n;
   pre[sum]++; 
  }
  REP(i,0,n)
  {
   ll m=pre[i];
   ans+=m*(m-1)/2;
  }
  cout<<ans<<endl;
 }
 return 0;
}