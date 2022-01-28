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
vector<ll> cntPrime(1000009);

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
 cntPrime[0]=cntPrime[1]=0;
 REP(i,2,n+1)
  cntPrime[i]=((isPrime[i])?cntPrime[i-1]+1:cntPrime[i-1]);
}
int main()
{
 sieve(1000000);
 ll t;
 cin>>t;
 while(t--)
 {
  ll ans=0,a,b;
  cin>>a>>b;
  if(a<=1)
    cout<<cntPrime[b]<<endl;
  else
   cout<<cntPrime[b]-cntPrime[a-1]<<endl;
 }
 return 0;
}