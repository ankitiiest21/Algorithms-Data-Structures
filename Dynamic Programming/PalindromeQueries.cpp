#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;
bool dp[1007][1007];

void fillPalindromicSubstrings(string s,int n)
{
 memset(dp,false,sizeof(dp));
 for(int i=0;i<n;i++)
  dp[i][i]=true;
 for(int i=n-1;i>=0;i--)
 {
  for(int j=i+1;j<n;j++)
  {
   if(s[i]==s[j])
   {
    if(j==i+1)
     dp[i][j]=true;
    else
     dp[i][j]=dp[i+1][j-1];
   }
  }
 }
}

int main()
{
  int n,m,a,b;
  string s;
  cin>>n;
  cin>>s;
  fillPalindromicSubstrings(s,n);
  cin>>m;
  for(int i=0;i<m;i++)
  {
   cin>>a>>b;
   cout<<((dp[a-1][b-1])?"YES":"NO")<<endl;
  }
  return 0;
}