#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll numOfUniqueSubsequences(string s)
{
 ll n=s.size();
 ll*dp=new ll[n];
 ll val[n][26]={0};
 REP(i,0,n)
 {
  dp[i]=0;
  for(char ch='A';ch<='Z';ch++)
  {
   if(ch==s[i])
   {
    if(i==0)
     val[i][ch-'A']=1;
    else
     val[i][ch-'A']=1+dp[i-1];
   }
   else
   {
    if(i==0)
     val[i][ch-'A']=0;
    else
     val[i][ch-'A']=val[i-1][ch-'A'];
   }
   dp[i]=((dp[i]%mod)+(val[i][ch-'A'])%mod)%mod;
  }
 }
 return (dp[n-1]+1)%mod;
}

int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  string s;
  cin>>s;
  cout<<numOfUniqueSubsequences(s)<<endl;
 }
 return 0;
}