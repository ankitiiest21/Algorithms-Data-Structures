#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll getAreaRainWater(ll a[],ll n)
{
 ll ans=0;
 ll left[n];
 ll right[n];
 left[0]=a[0],right[n-1]=a[n-1];
 REP(i,1,n)
  left[i]=max(left[i-1],a[i]);
 REPI(i,0,n-1)
  right[i]=max(right[i+1],a[i]);
 REP(i,0,n)
  cout<<left[i]<<" "<<right[i]<<endl;
 REP(i,0,n)
  ans+=min(left[i],right[i])-a[i];
 return ans;
}

int main()
{
 ll n;
 cin>>n;
 ll a[n];
 REP(i,0,n)
  cin>>a[i];
 cout<<getAreaRainWater(a,n)<<endl;
 return 0;
}