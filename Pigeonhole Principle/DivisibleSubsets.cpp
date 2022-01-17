//https://www.codechef.com/problems/DIVSUBS
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
int main()
{
  ll t=1;
  cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   ll a[n],sum=0;
   unordered_map<ll,vector<ll>> mp;
   REP(i,0,n)
   {
    cin>>a[i];
    sum+=a[i];
    sum%=n;
    sum=(sum+n)%n;
    mp[sum].PB(i);
   }
   if(mp[0].size())
   {
    cout<<mp[0][0]+1<<endl;
    REP(i,1,mp[0][0]+2)
     cout<<i<<" ";
    cout<<endl;
   }
   else
   {
    REPIT(it,mp)
    {
     if(mp[it->first].size()>=2)
     {
      auto i=mp[it->first].begin();
      // cout<<it->first<<endl;
      ll l=*i;
      i++;
      ll r=*i;
      cout<<r-l<<endl;
      REP(j,l+2,r+2)
       cout<<j<<" ";
      cout<<endl;
      break;
     }
    }
   }
  }
 return 0;
}