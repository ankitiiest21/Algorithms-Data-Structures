  
// O(n+m) solution where n=size of text, m=size of pattern, log n factor is eliminated by using hash(pattern)*pow_p[L]=dp[R]-dp[L-1] for checking.
// This is an implementation of Rabin Karp String Matching Algorithm

#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[1000007],pow_p[1000007];


void init(string s)
{
 dp[0]=(s[0]-'a'+1);
 pow_p[0]=1;
 ll p_pow=1,p=31;
 for(ll i=1;i<s.size();i++){
   p_pow=(p_pow*p)%mod;
   dp[i]=(dp[i-1]+p_pow*(s[i]-'a'+1))%mod;
   pow_p[i]=p_pow;
 }
}

ll substringHash(ll l,ll r)
{
 ll res=dp[r];
 if(l>0)
   res=(res-dp[l-1]+mod)%mod;
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
      if(substringHash(l,r)==(hashP*pow_p[l])%mod)
        cout<<l<<endl;
    }
    cout<<endl;
  }
  return 0;
}
