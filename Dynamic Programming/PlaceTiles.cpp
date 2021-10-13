#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll numOfWaysToPlaceTiles(ll n)
{
 ll fib1=1,fib2=2,fibn;
 if(n<=2)
  return ((n==2)?fib2:fib1);
 REP(i,3,n+1)
  fibn=((fib1%mod)+(fib2%mod))%mod,fib1=fib2%mod,fib2=fibn%mod;
 return fibn;
}

int main()
{
 ll n;
 cin>>n;
 cout<<numOfWaysToPlaceTiles(n)<<endl;
 return 0;
}