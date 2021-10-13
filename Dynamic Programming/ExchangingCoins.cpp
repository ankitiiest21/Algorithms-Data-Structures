#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
map<ll,ll> mp;

ll maxWeightOfGold(ll n)
{
 if(n<=1)
  return n;
 if(mp[n])
  return mp[n];
 return mp[n]=max(n,maxWeightOfGold(n/2)+maxWeightOfGold(n/3)+maxWeightOfGold(n/4));
}

int main()
{
 ll n;
 cin>>n;
 cout<<maxWeightOfGold(n)<<endl;
}