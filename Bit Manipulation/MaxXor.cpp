//https://codeforces.com/problemset/problem/276/D

#include<bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

int main()
{
 ll a,b;
 cin>>a>>b;
 if(a==b)
   cout<<"0\n";
 else
 {
  ll inda=0,indb=0,res,temp=1,ans=0;
  vl bina(64,0),binb(64,0);
  bool diffBitEncountered=false;
  while(a>0){
   bina[inda++]=(a&1);
   a=a>>1;
  }
  while(b>0){
   binb[indb++]=(b&1);
   b=b>>1;
  }
  REPI(i,0,max(inda,indb))
  {
   if(diffBitEncountered)
    res=1;
   else{
     if(bina[i]!=binb[i])
        diffBitEncountered=true;
     res=bina[i]^binb[i];
   }
   temp=(1ll<<i);
   ans+=res*temp;
  }
  cout<<ans<<endl;
 }
 return 0;
}