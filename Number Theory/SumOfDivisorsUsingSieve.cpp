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
vector<pair<ll,ll>> pf;

ll fast_power(ll a,ll n)
{
 ll ans=1;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    ans=ans*a;
  a=a*a;
  n=n>>1;
 }
 return ans;
}

void sieveInit()
{
 bool isPrime[1000009];
 memset(isPrime,true,sizeof(isPrime));
 isPrime[0]=isPrime[1]=false;
 for(ll i=2;i*i<=1000009;i++)
 {
  if(isPrime[i])
  {
   primes.push_back(i);
   for(ll j=i*i;j<=1000009;j+=i)
     isPrime[j]=false;
  }
 }
}
void primefactorizationUsingSieve(ll n)
{
 pf.clear();
 for(ll i=0;primes[i]*primes[i]<=n;i++)
 {
  ll cnt=0,currPrime=primes[i];
  if(n%currPrime==0)
  {
   while(n%currPrime==0)
   	n/=currPrime,cnt++;
   pf.push_back({currPrime,cnt});
  }
 }
 if(n!=1)
  pf.push_back({n,1});
}
int main()
{
 ll t;
 cin>>t;
 //Will take O(NloglogN) for pre-computation
 sieveInit();
 while(t--)
 {
  ll n;
  cin>>n;
  //O(logN) for each query
  primefactorizationUsingSieve(n);
  ll ans=1;
  REP(i,0,pf.size())
   ans*=(fast_power(pf[i].first,pf[i].second+1)-1)/(pf[i].first-1);
  cout<<ans<<endl;
 }
 return 0;
}