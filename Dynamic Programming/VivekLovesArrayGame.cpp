#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll bs(ll key,ll l,ll r,vector<ll> &v)
{
 if(l>r)
  return INT_MAX;
 ll mid=(l+r)/2;
 if(v[mid]==key)
  return min(mid,bs(key,l,mid-1,v));
 else if(v[mid]<key)
  return bs(key,mid+1,r,v);
 else
  return bs(key,l,mid-1,v);
}

ll maxScoreByDividingArrays(vector<ll> &v,ll start,ll end,map<pair<ll,ll>,ll> &dp)
{
 if(start>=end)
  return 0;
 if(dp.find({start,end})!=dp.end())
  return dp[{start,end}];
 ll sumSubarray=v[end]-v[start-1];
 if(sumSubarray%2)
  return 0;
 ll leftSumSubarray=(sumSubarray/2)+v[start-1];
 ll ind=min(end,bs(leftSumSubarray,start,end,v));
 if(ind<end&&v[end]-v[ind+1-1]==v[ind]-v[start-1])
  dp[{start,end}]=1+max(maxScoreByDividingArrays(v,start,ind,dp),maxScoreByDividingArrays(v,ind+1,end,dp));
 return dp[{start,end}];
}

int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
   ll n;
   cin>>n;
   vector<ll> v(n+1,0);
   REP(i,1,n+1)
    cin>>v[i],v[i]+=v[i-1];
   map<pair<ll,ll>,ll> dp;
   cout<<maxScoreByDividingArrays(v,1,n,dp)<<endl;
 }
 return 0;
}