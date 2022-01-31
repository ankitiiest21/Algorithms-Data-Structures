//https://codeforces.com/contest/1342/problem/C
#include<bits/stdc++.h>
#define ull unsigned long long
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
   ll a,b,q,l,r;
   cin>>a>>b>>q;
   vl v(a*b+1,0);
   REP(i,1,a*b)
   {
    if(i==0)
     v[i]=0;
    else
     v[i]=(((i%a)%b!=(i%b)%a)?1+v[i-1]:v[i-1]);
   }
   REP(i,0,q)
   {
    cin>>l>>r;
    ll ans=(r/(a*b))*v[a*b-1]+v[r%(a*b)];
    ans-=((l-1)/(a*b))*v[a*b-1]+v[(l-1)%(a*b)];
    cout<<ans<<" ";
   }
   cout<<endl;
  }
 return 0;
}