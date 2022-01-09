#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

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

int main()
{
 ll a,n;
 cin>>a>>n;
 cout<<fast_power(a,n)<<endl;
 return 0;
}