#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll findSum(ll a[],ll l,ll r)
{ 
 ll sum=0;
 REP(i,l,r+1)
  sum+=a[i],sum%=100;
 return sum; 
}

ll minSmokeToCombineMixtures(ll mix[],ll n)
{
 ll minSmoke[n+1][n+1];
 memset(minSmoke,0,sizeof(minSmoke));
 REP(d,0,n)
 {
  REP(i,0,n)
  {
   ll j=i+d;
   if(j<n)
   {
   	if(i==j)
   	minSmoke[i][j]=0;
   else if(j==i+1)
   	minSmoke[i][j]=mix[i]*mix[j];
   else
   {
    minSmoke[i][j]=INT_MAX;
   	REP(k,i,j+1)
   	 minSmoke[i][j]=min(minSmoke[i][j],minSmoke[i][k]+minSmoke[k+1][j]+findSum(mix,i,k)*findSum(mix,k+1,j));
   }
   
   }
   else
   	break;
  }
 }
 return minSmoke[0][n-1];
}

int main()
{
 ll n;
 while(cin>>n)
 {
  ll mix[n];
  REP(i,0,n)
   cin>>mix[i];
  cout<<minSmokeToCombineMixtures(mix,n)<<endl;
 }
 return 0;
}