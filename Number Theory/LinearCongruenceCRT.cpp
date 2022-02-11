#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll x,y,GCD;
void extendedEuclidMethod(ll a,ll b)
{
 if(b==0)
 {
  x=1,b=0,GCD=a;
  return;
 }
 extendedEuclidMethod(b,a%b);
 ll currX=y;
 ll currY=x-(a/b)*y;
 x=currX;
 y=currY;
}
int main()
{
 ll n,prod=1,ans=0;
 cin>>n;
 ll a[n],r[n],pp[n],inv[n];
 REP(i,0,n)
  cin>>a[i],prod*=a[i];
 REP(i,0,n)
  cin>>r[i],pp[i]=prod/a[i];
 REP(i,0,n)
 {
  extendedEuclidMethod(pp[i],a[i]);
  inv[i]=(x+a[i])%a[i];
 }
 REP(i,0,n)
  ans=((ans%prod)+((r[i]%prod)*(pp[i]%prod)*(inv[i]%prod))%prod)%prod;
 cout<<ans<<endl;
 return 0;
}