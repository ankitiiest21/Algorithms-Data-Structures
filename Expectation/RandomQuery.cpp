//https://codeforces.com/contest/846/problem/F
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
int main()
{
 ll t=1;
  // cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   //uniqueElements[i] will store the no. of unique elements in all subarrays ending at i
   ll a[n+1],uniqueElements[n+1],sum=0;
   //lastOccurence will store the index of the last occurence of an element
   unordered_map<ll,ll> lastOccurence;
   REP(i,1,n+1)
   {
    cin>>a[i];
    if(i==1)
     uniqueElements[i]=1;
    else
     uniqueElements[i]=uniqueElements[i-1]+i-lastOccurence[a[i]];
    lastOccurence[a[i]]=i;
   }
   REP(i,1,n+1)
    sum+=uniqueElements[i];
   ld ans=(2*sum-n)/(1.0*n*n);
   cout<<fixed<<setprecision(6)<<ans<<endl;
  }
 return 0;
}