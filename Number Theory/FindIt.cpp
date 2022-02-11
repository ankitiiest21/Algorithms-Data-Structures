#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
map<ll,ll> sum;
map<ll,ll> freq;

void sieveInit()
{
 for(ll i=2;i<=100009;i++)
 {
   for(ll j=i;j<=100009;j+=i)
     sum[i]+=freq[j];
 }
}

 
int main()
{
 ll t=1;
 // cin>>t;
 //Will take O(NloglogN) for pre-computation
 while(t--)
 {
  ll n,a,ans=1,q;
  cin>>n;
  //O(logN) for each query
  REP(i,0,n)
  {
   cin>>a;
   freq[a]++;
  }
  sieveInit();
  cin>>q;
  REP(i,0,q)
  {
   cin>>a;
   if(a!=1)
    cout<<sum[a]<<endl;
   else
    cout<<n<<endl;
  }
 }
 return 0;
}