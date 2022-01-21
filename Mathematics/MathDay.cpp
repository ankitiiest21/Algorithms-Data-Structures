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
int main()
{
 ll t=1;
  cin>>t;
  while(t--)
  {
   ll a,n,p;
   cin>>a>>n>>p;
   REP(i,2,n+1)
    a=fast_modulo_power(a,i,p);
   cout<<a%p<
 return 0;
} 	