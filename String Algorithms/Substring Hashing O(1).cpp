#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[1000007],inv[1000007];

ll power(ll a,ll n){
  ll res=1;
  while(n){
    if(n%2)
      res=(res*a)%mod;
    n/=2;
    a=(a*a)%mod;
  }
  return res;
}

void init(string s)
{
 dp[0]=(s[0]-'a'+1);
 inv[0]=1;
 ll p_pow=1,p=31;
 for(ll i=1;i<s.size();i++){
   p_pow=(p_pow*p)%mod;
   dp[i]=(dp[i-1]+p_pow*(s[i]-'a'+1))%mod;
   inv[i]=power(p_pow,mod-2);
 }
}

ll substringHash(ll l,ll r)
{
 ll res=dp[r];
 if(l>0)
   res-=dp[l-1];
 res=(res*inv[l])%mod;
 return res;
}

int main()
{
  string s;
  cin>>s;
  init(s);
  ll Q,l,r;
  cin>>Q;
  while(Q--){
   cin>>l>>r;
   cout<<substringHash(l,r)<<endl;
  }
  return 0;
}
