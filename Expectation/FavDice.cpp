//https://www.spoj.com/problems/FAVDICE/
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
   ll n;
   cin>>n;
   ld ans=0;
   REP(i,1,n+1)
    ans+=n/(i*1.0);
   cout<<fixed<<setprecision(2)<<ans<<endl; 
  }
 return 0;
}