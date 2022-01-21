#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll findSumOfDigits(ll n){
   ll sum=0;
   while(n>0)
    sum+=n%10,n/=10;
   return sum;
}


int main()
{
  ll t=1;
  // cin>>t;
  while(t--)
  {
   ll n,temp=0,sumDig=0,sumDigPrim=0;
   cin>>n;
   temp=n;
   while(temp>0)
   {
    sumDig+=temp%10;
    temp/=10;
   }
   for(ll i=2;i*i<=n;i++)
   {
    while(n%i==0)
    {
     sumDigPrim+=findSumOfDigits(i);
     n/=i;
    }
   }
   if(n!=1)
    sumDigPrim+=findSumOfDigits(n);
   if(sumDig==sumDigPrim) cout<<"1\n";
   else cout<<"0\n";
  }
  return 0;
}
