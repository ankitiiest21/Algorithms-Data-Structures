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
void primefactorizationOptimised(ll n)
{
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
 REP(i,0,pf.size())
  cout<<pf[i].first<<"^"<<pf[i].second<<endl;
}
int main()
{
 ll n;
 cin>>n;
 primefactorizationOptimised(n);
 return 0;
}