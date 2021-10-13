#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll dp[10007]={0};

ll noOfWaysToReachNthIndex(ll a[],ll n,ll k)
{
 dp[0]=1;
 REP(i,1,n)
 {
  if(!a[i])
  {
   REP(j,1,k+1)
   {
    if(i-j>=0)
     dp[i]=((dp[i]%mod)+(dp[i-j]%mod))%mod;
   }
  }
 }
 return dp[n-1];
}

int main()
{
 ll n,k;
 cin>>n>>k;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<noOfWaysToReachNthIndex(a,n,k)<<endl;
}