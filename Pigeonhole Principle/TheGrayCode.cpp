//https://www.codechef.com/problems/GRAYSC
#include<bits/stdc++.h>
#define ull unsigned long long 
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
int main()
{
   ull n;
   cin>>n;
   ull a[n],sum=0;
   unordered_map<ull,ull> ump;
   REP(i,0,n)
    cin>>a[i],ump[a[i]]++;
   if(n>=130)
    cout<<"Yes\n";
   else
   {
    bool flag=false;
    REP(i,0,n)
    {
     REP(j,i+1,n)
     {
      REP(k,j+1,n)
      {
       ull res=a[i]^a[j]^a[k];
       ull freq=ump[res];
       if(res==a[i]) freq--;
       if(res==a[j]) freq--;
       if(res==a[k]) freq--;
       if(freq>=1)
         flag=true;
      }
     }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
 return 0;
}