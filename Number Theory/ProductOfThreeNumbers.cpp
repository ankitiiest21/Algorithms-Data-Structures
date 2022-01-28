#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
vector<pair<ll,ll>> pf;
ll fast_power(ll a,ll n)
{
 ll ans=1;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    ans=ans*a;
  a=a*a;
  n=n>>1;
 }
 return ans;
}
void primefactorizationOptimised(ll n)
{
 pf.clear();
 for(ll i=2;i*i<=n;i++)
 {
  ll cnt=0;
  if(n%i==0)
  {
   while(n%i==0)
    n/=i,cnt++;
   pf.push_back({i,cnt});
  }
 }
 if(n!=1)
  pf.push_back({n,1});
 
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n,a,b,c;
  cin>>n;
  primefactorizationOptimised(n);
  if(pf.size()>=3)
  {
   a=fast_power(pf[0].first,pf[0].second);
   b=fast_power(pf[1].first,pf[1].second);
   c=n/(a*b);
   cout<<"YES\n";
   cout<<a<<" "<<b<<" "<<c<<endl;
  }
  else if(pf.size()==2)
  {
   if((pf[0].second+1)*(pf[1].second+1)<=6)
    cout<<"NO\n";
   else
   {
    a=pf[0].first,b=pf[1].first,c=n/(a*b);
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c<<endl;
   }
  }
  else
  {
   if(pf[0].second>=6)
   {
    a=pf[0].first;
    b=a*a;
    c=n/(a*b);
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c<<endl;
   }
   else
   {
    cout<<"NO\n";
   }
  }
 }
 return 0;
}