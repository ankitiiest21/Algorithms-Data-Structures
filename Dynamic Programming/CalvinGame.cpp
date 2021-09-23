#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define mod 1000000007
using namespace std;

//dpf stores the maximum score going only forward from kth index
//dpb stores the maximum score going forward from 1 to ith index which is same as coming backward from ith index to 1. 
ll maxSumCalvinGame(ll a[],ll n,ll k)
{
 ll ans=INT_MIN;
 ll*dpf=new ll[n];
 ll*dpb=new ll[n];
 REP(i,0,k)
  dpf[i]=0;
 REP(i,k,n)
 {
  if(i-2>=0)
  	dpf[i]=a[i]+max(dpf[i-1],dpf[i-2]);
  else
  	dpf[i]=a[i]+dpf[i-1];
 }
 dpb[0]=a[0];
 dpb[1]=a[0]+a[1];
 REP(i,2,n)
  dpb[i]=a[i]+max(dpb[i-1],dpb[i-2]);
 REP(i,k,n)
  ans=max(ans,dpf[i]+dpb[i]-a[i]);
 return ans;
}

int main()
{
 ll n,k;
 cin>>n>>k;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<maxSumCalvinGame(a,n,k)<<endl;
 return 0;
}