#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll maxProdSubarray(ll a[],ll n)
{
 ll dp[n][2],maxi=INT_MIN;
 dp[0][0]=max(a[0],0ll);
 dp[0][1]=min(a[0],0ll);
 REP(i,1,n)
 {
  if(a[i]<0)
  {
   dp[i][0]=max(0ll,dp[i-1][1]*a[i]);
   dp[i][1]=min(0ll,min(a[i],dp[i-1][0]*a[i]));
  }
  else
  {
   dp[i][0]=max(0ll,max(a[i],dp[i-1][0]*a[i]));
   dp[i][1]=min(0ll,dp[i-1][1]*a[i]);
  }
 }
 REP(i,0,n)
  maxi=max(maxi,dp[i][0]);
 return maxi;
}

ll maxProdSubarrayOptimised(ll a[],ll n)
{
 ll max_pos_prod_so_far=max(0ll,a[0]),max_neg_prod_so_far=min(0ll,a[0]);
 ll maxi=max_pos_prod_so_far;
 REP(i,1,n)
 {
  ll max_pos_prod_just_before=max_pos_prod_so_far;
  ll max_neg_prod_just_before=max_neg_prod_so_far;
  if(a[i]<0)
  {
   max_pos_prod_so_far=max(0ll,max_neg_prod_so_far*a[i]);
   max_neg_prod_so_far=min(0ll,min(a[i],a[i]*max_pos_prod_just_before));
  }
  else
  {
   max_pos_prod_so_far=max(0ll,max(a[i],max_pos_prod_just_before*a[i]));
   max_neg_prod_so_far=min(0ll,a[i]*max_neg_prod_just_before);
  }
  maxi=max(maxi,max_pos_prod_so_far);
 }
 return maxi;
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<maxProdSubarrayOptimised(a,n)<<endl;
 return 0;
}