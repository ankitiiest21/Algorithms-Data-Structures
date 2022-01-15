// https://www.spoj.com/problems/SEQ/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000000
#define MAXI 10000000000
using namespace std;
ll k;
vector<ll> a,b(25),c(25);

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
 vector<vector<ll>> C(k+1,vector<ll>(k+1));
 REP(i,1,k+1)
 {
  REP(j,1,k+1)
  {
   REP(x,1,k+1)
    C[i][j]=((C[i][j]%mod)+((A[i][x]%mod)*(B[x][j]%mod))%mod)%mod;
  }
 }
 return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A,ll n)
{
 if(n==1)
  return A;
 if(n&1)
  return multiply(A,pow(A,n-1));
 vector<vector<ll>> X=pow(A,n/2);
 return multiply(X,X);
}

ll calculate(ll n)
{
 if(n<=k)
  return b[n-1];
 //Step-1: Find F1
 vector<ll> F1(k+1);
 REP(i,1,k+1)
  F1[i]=b[i-1];
 //Step-2: Find Transformation Matrix
 vector<vector<ll>> T(k+1,vector<ll>(k+1));
 REP(i,1,k+1)
 {
  REP(j,1,k+1)
  {
   if(i<k)
   {
    if(j==i+1)
     T[i][j]=1;
    else
     T[i][j]=0;
   }
   else
   {
    T[i][j]=c[k-j];
   }
  }
 }
 //Step-3: Finding T^(n-1)
 T=pow(T,n-1);
 //Step-4: Fn=T^(n-1)*F1
 ll res=0;
 REP(j,1,k+1)
  res=((res%mod)+((T[1][j]%mod)*(F1[j]%mod))%mod)%mod;
 return res;
}

int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  cin>>k;
  REP(i,0,k)
   cin>>b[i];
  REP(i,0,k)
   cin>>c[i];
  ll n;
  cin>>n;
  cout<<calculate(n)<<endl;
  b.clear();
  c.clear();
 }
 return 0;
}