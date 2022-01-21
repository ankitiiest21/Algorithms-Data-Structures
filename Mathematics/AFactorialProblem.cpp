//https://hack.codingblocks.com/app/practice/1/137/problem
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
int main()
{
  ll t=1;
  cin>>t;
  while(t--)
  {
   ll n,k,ans=LLONG_MAX;
   cin>>n>>k;
   for(ll i=2;i*i<=k;i++)
   {
    if(k%i==0)
    {
     ll expOfIinK=0;
     while(k%i==0)
      expOfIinK++,k/=i;
     ll expOfIinNfac=0,p=i;
     while(p<=n)
      expOfIinNfac+=n/p,p*=i;
     ans=min(ans,expOfIinNfac/expOfIinK);
    }
   }
   if(k>1)
   {
    ll expOfIinK=1;
    ll expOfIinNfac=0,p=k;
    while(p<=n)
      expOfIinNfac+=n/p,p*=k;
    ans=min(ans,expOfIinNfac/expOfIinK);
   }
   cout<<ans<<endl;
  }
 return 0;
}