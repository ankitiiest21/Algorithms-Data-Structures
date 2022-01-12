#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

void multiply(ll*a,ll &n,ll num)
{
 ll carry=0;
 REP(i,0,n)
 {
  ll product=a[i]*num+carry;
  a[i]=product%10;
  carry=product/10;
 }
 while(carry)
 {
  a[n++]=carry%10;
  carry/=10;
 }
}

void big_factorial(ll n){
	ll*a=new ll[1000];
	REP(i,0,1000)
	 a[i]=0;
	a[0]=1;
	ll numofdigits=1;
    REP(i,2,n+1)
     multiply(a,numofdigits,i);
    REPI(i,0,numofdigits)
     cout<<a[i];
}

int main()
{
 ll n;
 cin>>n;
 big_factorial(n);
 return 0;
}