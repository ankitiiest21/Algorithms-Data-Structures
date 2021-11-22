#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

bool sortbyfunc(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
 return (abs(a.first-a.second)>=abs(b.first-b.second));
}

int main()
{
 ll n,a,b;
 cin>>n>>a>>b;
 vector<pair<ll,ll>> vp(n);
 REP(i,0,n)
  cin>>vp[i].first;
 REP(i,0,n)
  cin>>vp[i].second;
 sort(vp.begin(),vp.end(),sortbyfunc);
 ll ans=0,andy=0,bob=0;
 REP(i,0,n)
 {
  if(vp[i].first>vp[i].second)
  {
   if(andy+1<=a)
   {
    andy++;
    ans+=vp[i].first;
   }
   else
   {
   	bob++;
   	ans+=vp[i].second;
   }
  }
  else
  {
   if(bob+1<=b)
   {
   	bob++;
   	ans+=vp[i].second;
   }
   else
   {
   	andy++;
   	ans+=vp[i].first;
   }
  }
 }
 cout<<ans<<endl;
}