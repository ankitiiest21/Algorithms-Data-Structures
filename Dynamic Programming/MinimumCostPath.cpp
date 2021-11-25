#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;
ll dp[1009][1009],path[1009][1009];

void minCostPathToReachBottomRightCell(vector<vector<ll>> a)
{
 ll n=a.size(),m=a[0].size();
 memset(dp,0,sizeof(dp));
 memset(path,0,sizeof(path));
 dp[0][0]=a[0][0];
 path[0][0]=-1;
 REP(i,1,n)
  dp[i][0]=dp[i-1][0]+a[i][0],path[i][0]=(i-1)*m;
 REP(j,1,m)
  dp[0][j]=dp[0][j-1]+a[0][j],path[0][j]=j-1;
 REP(i,1,n)
 {
  REP(j,1,m)
  {
   if(dp[i-1][j]<=dp[i][j-1])
   	dp[i][j]=a[i][j]+dp[i-1][j],path[i][j]=(i-1)*m+j;
   else
   	dp[i][j]=a[i][j]+dp[i][j-1],path[i][j]=i*m+j-1;
  }
 }

}

int main()
{
 ll n,m;
 cin>>n>>m;
 vector<vector<ll>> a(n,vector<ll>(m,0));
 REP(i,0,n)
  REP(j,0,m)
   cin>>a[i][j];
 minCostPathToReachBottomRightCell(a);
 cout<<"Minimum cost: "<<dp[n-1][m-1]<<endl;
 cout<<"Minimum cost path: ";
 vector<pair<ll,ll>> vp;
 vp.push_back({n-1,m-1});
 ll row=n-1,col=m-1;
 while(path[row][col]!=-1)
 {
  ll temp=path[row][col];
  row=temp/m;
  col=temp%m;
  vp.push_back({row,col});
 }
 reverse(vp.begin(),vp.end());
 REP(i,0,vp.size())
 {
  if(i!=vp.size()-1)
  	cout<<"("<<vp[i].first<<","<<vp[i].second<<") -> ";
  else
  	cout<<"("<<vp[i].first<<","<<vp[i].second<<")"<<endl;
 }
 return 0;
}