#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll maxPriceCut(ll price[],ll n)
{
 ll dp[n+1]={0};
 REP(i,1,n+1)
 {
  REP(j,0,i+1)
   dp[i]=max(dp[i],price[j]+dp[i-j]);
 }
 return dp[n];
}

int main()
{
 ll n;
 cin>>n;
 ll price[n+1];
 price[0]=0;
 REP(i,1,n+1)
  cin>>price[i];
 cout<<maxPriceCut(price,n)<<endl;
}