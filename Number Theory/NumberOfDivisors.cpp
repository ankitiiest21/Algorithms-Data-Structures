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
map<ll,ll> freqPF;

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
void fillPrimeFactors(ll n)
{
 for(ll i=0;primes[i]*primes[i]<=n;i++)
 {
  ll cnt=0,currPrime=primes[i];
  if(n%currPrime==0)
  {
   while(n%currPrime==0)
   	n/=currPrime,cnt++;
   freqPF[currPrime]+=cnt;
  }
 }
 if(n!=1)
  freqPF[n]+=1;
 
}
int main()
{
 ll t;
 cin>>t;
 //Will take O(NloglogN) for pre-computation
 sieveInit();
 while(t--)
 {
  ll n,a,ans=1;
  cin>>n;
  //O(logN) for each query
  REP(i,0,n)
  {
   cin>>a;
   fillPrimeFactors(a);
  }
  for(auto it=freqPF.begin();it!=freqPF.end();it++)
  {
   ans=((ans%mod)*((it->second+1)%mod))%mod;
  }
  cout<<ans<<endl;
 }
 return 0;
}