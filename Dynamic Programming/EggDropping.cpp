#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

//O(e*f*f) approach which can give TLE in some cases..
ll minAttemptToFindCriticalFloor(ll f,ll e)
{
 ll dp[e+1][f+1];
 memset(dp,0,sizeof(dp));
 for(int i=1;i<e+1;i++)
 {
  for(int j=1;j<f+1;j++)
  {
   if(i==1)
   	dp[i][j]=j;
   else
   {
    ll temp=INT_MAX;
    for(int x=1;x<=j;x++)
    {
     //When ith egg breaks on dropping from xth floor, critical floor may be in [1,x] => dp[i-1][x-1]
     //When ith egg remains intact on dropping from xth floor, critical floor must be in [x+1,j] => dp[i][j-x]
     temp=min(temp,1+max(dp[i-1][x-1],dp[i][j-x]));
    }
    dp[i][j]=temp;
   }
  }
 }
 return dp[e][f];
}

//O(e*f*log(f)) solution
ll minAttemptToFindCriticalFloorOptimised(ll f,ll e)
{
 ll dp[e+1][f+1];
 memset(dp,0,sizeof(dp));
 for(int i=1;i<e+1;i++)
 {
  for(int j=1;j<f+1;j++)
  {
   if(i==1)
   	dp[i][j]=j;
   else if(j==1)
   	dp[i][j]=j;
   else
   {
    ll temp=INT_MAX;
    //When ith egg breaks on dropping from xth floor, critical floor may be in [1,x] => dp[i-1][x-1]
    //When ith egg remains intact on dropping from xth floor, critical floor must be in [x+1,j] => dp[i][j-x]
    ll l=1,r=j,top,bottom;
    while(l<r)
    {
     ll mid=l+(r-l)/2;
     top=dp[i][j-mid];
     bottom=dp[i-1][mid-1];
     if(bottom>top)
      r=mid;
     else
      l=mid+1;
     temp=min(temp,1+max(bottom,top));
    } 
    dp[i][j]=temp;
   }
  }
 }
 return dp[e][f];
}


int main()
{
 //f->num of floors,e->num of eggs
 ll f,e;
 cin>>f>>e;
 cout<<minAttemptToFindCriticalFloorOptimised(f,e)<<endl;
 return 0;
}