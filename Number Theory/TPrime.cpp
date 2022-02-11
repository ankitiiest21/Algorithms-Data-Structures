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
vector<ll> primes;

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
 primes.push_back(2);
 for(ll i=3;i<=n;i+=2)
 {
  if(isPrime[i])
  {
   primes.push_back(i);
   for(ll j=i*i;j<=n;j+=i)
   	isPrime[j]=false;
  }
 }
}

int main()
{
 sieve(1000000);
 cout<<primes.size()<<endl;
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
 {
  cin>>a[i];
  ll sqRoot=sqrt(a[i]);
  if(sqRoot*sqRoot==a[i]&&isPrime[sqRoot])
  	cout<<"YES\n";
  else
  	cout<<"NO\n";
 }
 return 0;
}