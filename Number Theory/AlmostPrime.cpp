//https://codeforces.com/problemset/problem/26/A
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll noOfPrimeFactors[3005];

ll sieve(ll n)
{
 ll ans=0;
 memset(noOfPrimeFactors,0ll,sizeof(noOfPrimeFactors));
 noOfPrimeFactors[0]=noOfPrimeFactors[1]=0;
 for(ll i=2;i<=n;i++)
 {
  if(!noOfPrimeFactors[i])
  {
   for(ll j=2*i;j<=n;j+=i)
      noOfPrimeFactors[j]++;
  }
 }
 REP(i,1,n+1)
  if(noOfPrimeFactors[i]==2)
    ans++;
 return ans;
}
int main()
{
 ll n;
 cin>>n;
 cout<<sieve(n)<<endl;
 return 0;
}