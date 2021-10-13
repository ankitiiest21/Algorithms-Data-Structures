#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll numOfDecryptedStrings(string s)
{
 ll*dp=new ll[s.size()];
 dp[0]=1;
 REP(i,1,s.size())
 {
  if(s[i]!='0')
   dp[i]=dp[i-1];
  else
   dp[i]=0;
  string temp;
  temp+=s[i-1];
  temp+=s[i];
  // cout<<temp<<endl;
  if(i!=1)
  {
   if(temp>="10"&&temp<="26")
   	dp[i]+=dp[i-2];
  }
  else
  {
   if(temp>="10"&&temp<="26")
   	dp[i]+=1;
  }
 }
 return dp[s.size()-1];
}

int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  string s;
  cin>>s;
  cout<<numOfDecryptedStrings(s)<<endl;
 }
 return 0;
}