#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll fast_modulo_power(ll a,ll n,ll p)
{
 ll ans=1;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    ans=((ans%p)*(a%p))%p;
  a=((a%p)*(a%p))%p;
  n=n>>1;
 }
 return ans%p;
}
ll factorial(ll n)
{
 ll ans=1;
 REP(i,2,n+1)
  ans=((ans%mod)*(i%mod))%mod;
 return ans;
}
int main()
{
 ll n,r;
 cin>>n>>r;
 ll ans=factorial(n);
 ll ans1=factorial(r);
 ans1=fast_modulo_power(ans1,mod-2,mod);
 ll ans2=factorial(n-r);
 ans2=fast_modulo_power(ans2,mod-2,mod);
 ans=((ans%mod)*(ans1%mod))%mod;
 ans=((ans%mod)*(ans2%mod))%mod;
 cout<<ans<<endl;
 return 0;
}