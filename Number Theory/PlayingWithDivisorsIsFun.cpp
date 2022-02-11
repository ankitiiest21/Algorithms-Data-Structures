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
map<ll,ll> freq;

ll fast_modulo_power(ll a,ll n,ll p)
{
 ll ans=1;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    ans=((ans%p)*(a%p))%p;
  a=((a%p)*(a%p))%p;
  n=n>>1;
 }
 return ans%p;
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

int main()
{
 ll t=1;
//  cin>>t;
 //Will take O(NloglogN) for pre-computation
 sieveInit();
 while(t--)
 {
  ll n;
  cin>>n;
  //O(logN) for each query
  ll a[n],prod=1,ans=1;
  REP(i,0,n)
   cin>>a[i],freq[primes[i]]=a[i],prod=((prod%mod)*(a[i]+1)%mod)%mod;
  REP(i,0,n)
  {
   ll temp=0;
   ll q=((prod%mod)*(fast_modulo_power(a[i]+1,mod-2,mod))%mod)%mod;
   ll num=freq[primes[i]];
   temp = (num*(num+1))%mod;
   temp = (temp*q)%mod;
   temp = (temp*fast_modulo_power(2,mod-2,mod))%mod;
   temp=(temp+1)%mod;
   ans=((ans%mod)*(temp%mod))%mod;
  }
  cout<<ans<<endl;
 }
 return 0;
}