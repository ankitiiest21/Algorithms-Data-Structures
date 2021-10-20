#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll dp[5020][5020];
ll choc[5020],candy[5020],n,m;

ll minSumAbsoluteDiffBetweenAllPairs(ll i,ll j)
{
 if(i==n)
  return 0;
 if(j==m)
  return MAXI;
 if(dp[i][j]!=-1)
  return dp[i][j];
 ll op1=abs(choc[i]-candy[j])+minSumAbsoluteDiffBetweenAllPairs(i+1,j+1);
 ll op2=minSumAbsoluteDiffBetweenAllPairs(i,j+1);
 return dp[i][j]=min(op1,op2);
}

int main()
{
 cin>>n>>m;
 REP(i,0,n)
  cin>>choc[i];
 REP(i,0,m)
  cin>>candy[i];
 sort(choc,choc+n);
 sort(candy,candy+m);
 memset(dp,-1,sizeof(dp));
 cout<<minSumAbsoluteDiffBetweenAllPairs(0,0)<<endl;
 return 0;
}