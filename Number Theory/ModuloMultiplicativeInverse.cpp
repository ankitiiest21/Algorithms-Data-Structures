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

void findModuloMultiplicativeInverse(ll a,ll m)
{
 if(__gcd(a,m)!=1)
 {
  cout<<"Modulo multiplicative inverse doesn't exist"<<endl;
  return;
 }
 extendedEuclidMethod(a,m);
 cout<<"Modulo multiplicative inverse of "<<a<<" wrt "<<m<<" is: "<<(x+m)%m<<endl;
}


int main()
{
 ll a,m;
 cin>>a>>m;
 findModuloMultiplicativeInverse(a,m);
 return 0;
}