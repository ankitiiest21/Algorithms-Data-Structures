#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

int main()
{
 ll t;
 cin>>t;
 ll primes[8]={2,3,5,7,11,13,17,19};
 while(t--)
 {
  ll ans=0,n;
  cin>>n;
  ll subsets=(1<<8);
  REP(i,1,subsets)
  {
   ll deno=1ll;
   ll setBits=__builtin_popcount(i);
   REP(j,0,8)
   {
    if(i&(1<<j))
     deno*=primes[j];
   }
   if(setBits&1)
    ans+=n/deno;
   else
    ans-=n/deno;
  }
  cout<<ans<<endl;
 }
 return 0;
}