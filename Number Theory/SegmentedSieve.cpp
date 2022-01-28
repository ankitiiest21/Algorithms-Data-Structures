//https://www.spoj.com/problems/PRIME1/
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
vector<ll> primes;
vector<bool> isPrime(100009);

void sieve()
{
 REP(i,0,100009)
 {
  if(i%2==0)
  	isPrime[i]=false;
  else
  	isPrime[i]=true;
 }
 isPrime[0]=isPrime[1]=false;
 isPrime[2]=true;
 primes.push_back(2);
 for(ll i=3;i*i<=100009;i+=2)
 {
  if(isPrime[i])
  {
   primes.push_back(i);
   for(ll j=i*i;j<=100009;j+=i)
   {
   	isPrime[j]=false;
   }
  }
 }
 // REP(i,0,100)
 //  cout<<primes[i]<<" ";
 // cout<<endl;
}
int main()
{
 sieve();
 ll t;
 cin>>t;
 while(t--)
 {
  ll m,n;
  cin>>m>>n;
  bool segment[n-m+1];
  REP(i,0,n-m+1)
   segment[i]=0;
  for(auto eachPrime:primes)
  {
   if(eachPrime*eachPrime>n)
   	 break;
   ll start=(m/eachPrime)*eachPrime;
   if(eachPrime>=m&&eachPrime<=n)
   	start=2*eachPrime;
   for(ll j=start;j<=n;j+=eachPrime)
   	segment[j-m]=1;
  }
  REP(i,m,n+1)
   if(segment[i-m]==0&&i!=1)
   	cout<<i<<endl;
  cout<<endl;
 }
 return 0;
}