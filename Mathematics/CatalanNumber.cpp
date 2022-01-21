#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll calculate_nCr(ll n,ll r)
{
 if(r>n)
   return 0;
 if(r>n-r)
   r=n-r;
 ll a[r],ans=1;
 REP(i,n-r+1,n+1)
  a[i+r-n-1]=i;
 REP(k,1,r+1)
 {
  ll j=0,i=k;
  while(j<r)
  {
   ll x=__gcd(i,a[j]);
   if(x>1)
    a[j]/=x,i/=x;
   if(i==1)
    break;
   j++;
  }
 }
 REP(i,0,r)
  ans=ans*a[i];
 return ans;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  ll t=1;
  // cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   cout<<calculate_nCr(2*n,n)/(n+1)<<endl;
  }
  return 0;
}