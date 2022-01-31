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

ll StringToInt(string a,ll m)
{
 ll ans=0;
 REP(i,0,a.size())
  ans=((ans*10)%m+a[i]-'0')%m;
 return ans;
}

int main()
{
 //1<=a,b<=10^(10^5)
 string a,b;
 cin>>a>>b;
 ll x=StringToInt(a,mod);
 ll y=StringToInt(b,mod-1);
 cout<<fast_modulo_power(x,y,mod)<<endl;
 return 0;
}