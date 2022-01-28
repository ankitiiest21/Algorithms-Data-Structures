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
 ll a,b;
 cin>>a>>b;
 extendedEuclidMethod(a,b);
 cout<<"Solution of the equation of the form "<<a<<"x+"<<b<<"y="<<__gcd(a,b)<<" is ("<<x<<","<<y<<")"<<endl;
 return 0;
}