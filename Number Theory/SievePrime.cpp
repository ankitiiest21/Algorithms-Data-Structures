#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
vector<bool> isPrime(1000009);

void sieve(ll n)
{
 REP(i,0,n+1)
 {
  if(i%2)
  	isPrime[i]=true;
  else
  	isPrime[i]=false;
 }
 isPrime[2]=true;
 isPrime[0]=isPrime[1]=false;
 for(ll i=3;i<=n;i+=2)
 {
  if(isPrime[i])
  {
   for(ll j=i*i;j<=n;j+=i)
   	isPrime[j]=false;
  }
 }
}
int main()
{
 ll n;
 cin>>n;
 sieve(n);
 REP(i,1,n+1)
  if(isPrime[i])
  cout<<i<<" ";
 return 0;
}