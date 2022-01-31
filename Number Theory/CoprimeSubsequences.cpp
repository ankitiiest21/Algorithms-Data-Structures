//https://codeforces.com/contest/803/problem/F
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
const int N=100005;
ll a[N], prime_count[N], mobius[N];
ll pow2[N];

void mobiusUtil()
{
 ll i, j;
    for (i = 1; i < N; i++) {
        a[i] = 1;
    }
    for (i = 2; i < N; i++) {
        if (prime_count[i]) continue;
        for (j = i; j < N; j += i) {
            prime_count[j]++;
            a[j] *= i;
        }
    }
    for (i = 1; i < N; i++) {
        if (a[i] == i) {
            // square free number
            if (prime_count[i] % 2 == 1) mobius[i] = -1;
            else mobius[i] = 1;
        }
        else {
            mobius[i] = 0;
        }
    }
}

int main()
{
 mobiusUtil();
//  REP(i,0,15)
//   cout<<mobius[i]<<endl;
 ll n,cnt=0,ans=0;
 cin>>n;
 ll a[n];
 map<ll,ll> mp;
 REP(i,0,n)
  cin>>a[i],mp[a[i]]++;
 pow2[0]=1;
 REP(i,1,N)
  pow2[i]=pow2[i-1]*2,pow2[i]%=mod;
 REP(i,1,N)
 {
  cnt=0;
  for(ll j=i;j<N;j+=i)
    cnt+=mp[j];
  ll temp=pow2[cnt]-1;
  ans+=mobius[i]*temp;
  ans%=mod;
 }
 ans+=mod;
 cout<<ans%mod<<endl;
 return 0;
}