//https://codeforces.com/contest/1244/problem/C
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll modInverse(ll a, ll m)
{
   if (m == 1) return 0;
   ll m0 = m, y = 0, x = 1;
 
   while (a > 1)
   {
      ll q = a / m, t = m;
      m = a % m, a = t;
      t = y;
      y = x - q * y;
      x = t;
   }
   if (x < 0) x += m0;
 
   return x;
}

int main()
{
   ll n,p,w,d,x,y;
   cin>>n>>p>>w>>d;
   ll g=__gcd(w,d);
   if(p%g!=0)
    cout<<"-1\n";
   //when all the matches result in a win 
   else if(w*n<p)
    cout<<"-1\n";
   else
   {
    p/=g;
    w/=g;
    d/=g;
    y=((p%w)*modInverse(d,w))%w;
    x=(p-y*d)/w;
    if(x+y>n||x<0)
     cout<<"-1\n";
    else
     cout<<x<<" "<<y<<" "<<n-(x+y)<<endl;
 return 0;
}