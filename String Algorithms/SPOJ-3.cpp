// n-size of text,m-size of pattern
// Time Complexity - O(n), Space Complexity - O(m)
#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
#define mod 1000000007
#define REP(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
ll prefixPI[1000007];
void fillPrefix(string s)
{
 prefixPI[0]=0;
 REP(i,1,s.size())
 {
  ll j=prefixPI[i-1];
  while(j>0&&s[i]!=s[j])
    j=prefixPI[j-1];
  if(s[i]==s[j])
    j++;
  prefixPI[i]=j;
 }
}


int main()
{
  ll n;
  while(cin>>n)
  {
    string p,t;
    cin>>p;
    cin>>t;
    fillPrefix(p);
    ll i=0,j=0,n=t.size(),m=p.size();
    while(i<n)
    {
     if(p[j]==t[i])
       i++,j++;
     if(j==m){
      cout<<i-j<<endl;
      j=prefixPI[j-1];
     }
     else if(i<n&&p[j]!=t[i]){
      if(j!=0)
        j=prefixPI[j-1];
      else
        i++;
     } 
    }
    cout<<"\n";
  }
  return 0;
}
