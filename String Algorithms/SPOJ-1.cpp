// O(nlogn+m) solution where n=size of text, m=size of pattern, log n factor is due to modular inverse being calculated at every step
// Same approach as substring hashing in O(1)

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
   res=(res-dp[l-1]+mod)%mod;
 res=(res*inv[l])%mod;
 return res;
}

ll calculateHash(string s)
{
 ll p_pow=1,p=31;
 ll res=0;
 for(char ch:s)
 {
  res=(res+p_pow*(ch-'a'+1))%mod;
  p_pow=(p_pow*p)%mod;
 }
 return res;
}

int main()
{
  ll n;
  while(cin>>n)
  {
    string p,t;
    cin>>p;
    cin>>t;
    init(t);
    ll hashP=calculateHash(p);
    for(int l=0,r=p.size()-1;r<t.size();l++,r++){
      if(substringHash(l,r)==hashP)
        cout<<l<<endl;
    }
    cout<<endl;
  }
  return 0;
}
