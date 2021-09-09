#include<bits/stdc++.h>
#include<iostream>
long long dp[1007][1007]={0};

using namespace std;

long long getMaxProfitBySellWines(int price[],int n)
{
 long long dp[n][n]={0};

  for(int i=n-1;i>=0;i--)
   for(int j=0;i+j<=n-1;j++)
     dp[i][j]=0;
  for(int d=0;d<=n-1;d++)
  {
   for(int i=0,j=i+d;i<n&&j<n;i++,j++)
   {
    if(j==i)
     dp[i][j]=n*price[j];
    else
     dp[i][j]=max(price[i]*(n-j+i)+dp[i+1][j],price[j]*(n-j+i)+dp[i][j-1]);
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
   }
  }
 return dp[0][n-1];
}

int main()
{
 int n;
 cin>>n;
 int price[n];
 for(int i=0;i<n;i++)
  cin>>price[i];
 cout<<getMaxProfitBySellWines(price,n)<<endl;
 return 0;
}