#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

ll find_gcd(ll a,ll b)
{
 return ((b==0?a:find_gcd(b,a%b)));
}

int main()
{
 ll n1,n2;
 cin>>n1>>n2;
 cout<<find_gcd(max(n1,n2),min(n1,n2))<<endl;
 return 0;
}