//https://www.spoj.com/problems/DCEPC11B/
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll n,p;

ll fast_modulo_power(ll a,ll n,ll p)
{
 ll ans=1;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    ans=(ans*a)%p;
  a=(a*a)%p;
  n=n>>1;
 }
 return ans%p;
}

ll solve()
{
 ll ans=-1;
 REP(i,n+1,p)
 {
  ll temp=fast_modulo_power(i,p-2,p);
  ans=(ans*temp)%p;
 }
  
 return (ans+p);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
 ll t;
 cin>>t;
 while(t--)
 {
  cin>>n>>p;
  if(n>=p)
   cout<<"0\n";
  else
   cout<<solve()<<endl;
 }
 return 0;
}