#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
using namespace std;

ll maxLengthOfValidParenthesisSubstring(string s)
{
 ll n=s.size(),maxi=INT_MIN;
 ll*dp=new ll[n];
 stack<ll> st;
 REP(i,0,n)
 {
  if(s[i]=='(')
  	dp[i]=0,st.push(i);
  else
  {
   if(st.empty())
   	dp[i]=0;
   else
   {
   	ll j=st.top();
   	st.pop();
   	dp[i]=(i-j+1)+((j>=1)?dp[j-1]:0);
   }
  }
 }
 REP(i,0,n)
  maxi=max(maxi,dp[i]);
 return maxi;
}

int main()
{
 string s;
 cin>>s;
 cout<<maxLengthOfValidParenthesisSubstring(s)<<endl;
 return 0;
}