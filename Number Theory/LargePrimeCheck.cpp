#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
bitset<10000000> isPrime;
vector<ll> primes;


void sieve()
{
 isPrime.set();
 isPrime[0]=isPrime[1]=0;
 for(ll i=2;i<=10000000;i+=2)
 {
  if(i%2==0)
  	isPrime[i]=0;
 }
 for(ll i=3;i<=10000000;i+=2)
 {
  if(isPrime[i])
  {
   primes.push_back(i);
   for(ll j=i*i;j<=10000000;j+=i)
   	isPrime[j]=0;
  }
 }
}

string ifPrime(ll n)
{
 if(n<=10000000)
    return ((isPrime[n])?"Yes":"No");
 else
 {
  for(ll i=0;primes[i]*primes[i]<=n;i++)
  {
   if(n%primes[i]==0)
    return "No";
  }
 }
 return "Yes";
}

int main()
{
 sieve();
 ll n;
 cin>>n;
 cout<<ifPrime(n)<<endl;
 return 0;
}