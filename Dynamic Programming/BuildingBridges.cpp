#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

bool sortbyfunc(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
 if(a.first==b.first)
  return a.second<b.second;
 return a.first<b.first;
}

ll maxNoOfNonIntersectingBridges(vector<pair<ll,ll>> bridge,ll n)
{
 ll lis[n];
 sort(bridge.begin(),bridge.end(),sortbyfunc);
 REP(i,0,n)
  lis[i]=1;
 REP(i,1,n)
 {
  REP(j,0,i)
  {
   if(bridge[j].second<=bridge[i].second&&lis[i]<1+lis[j])
   	lis[i]=1+lis[j];
  }
 }
 return *max_element(lis,lis+n);
}

int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  vector<pair<ll,ll>> bridge(n);
  REP(i,0,2*n)
  {
   if(i<n)
   	cin>>bridge[i].first;
   else
   	cin>>bridge[i-n].second;
  }
  cout<<maxNoOfNonIntersectingBridges(bridge,n)<<endl;
 }
 return 0;
}