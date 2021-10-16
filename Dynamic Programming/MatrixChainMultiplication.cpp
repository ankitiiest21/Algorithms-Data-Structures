#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll minCostToMultiplyMatrices(ll mat[],ll n)
{
 ll dp[n+1][n+1];

 REP(d,0,n)
 {
  REP(i,0,n)
  {
    ll j=i+d;
    dp[i][j]=INT_MAX;
    if(i==j)
     dp[i][j]=0;
    else
    {
     REP(k,i,j)
      dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+mat[i]*mat[k+1]*mat[j+1]);
    }
   }
 }
 // REP(i,0,n)
 // {
 //  REP(j,0,n)
 //   cout<<dp[i][j]<<" ";
 //  cout<<endl;
 // }
 return dp[0][n-1];
}

int main()
{
 ll n;
 cin>>n;
 //mat[0] will be the row size of 1st matrix
 //mat[1] will be the row size of 2nd matrix
 //Similarly, mat[n-2] will be the row size of (n-1)th matrix
 // mat[n-1] will be the col size of (n-1)th matrix
 //So, there are a total of (n-1)th matrix as input
 ll mat[n];
 REP(i,0,n)
  cin>>mat[i];
 cout<<minCostToMultiplyMatrices(mat,n-1)<<endl;
 return 0;
}