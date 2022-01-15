//https://www.spoj.com/problems/SPP/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
ll n,m,p;
ll k;
vector<ll> b(25),c(25);

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
 vector<vector<ll>> C(k+2,vector<ll>(k+2));
 REP(i,1,k+2)
 {
  REP(j,1,k+2)
  {
   REP(x,1,k+2)
    C[i][j]=((C[i][j]%p)+((A[i][x]%p)*(B[x][j]%p))%p)%p;
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

ll calculate()
{
 ll sum=0;
 REP(i,0,k)
   sum+=b[i];
 if(n<=k)
 {
  sum=0;
  REP(i,m-1,n)
   sum+=b[i];
  return sum;
 }
 //Step-1: Find F1
 vector<ll> F1(k+2);
 REP(i,1,k+2)
 {
  if(i==1)
   F1[i]=sum; 
  else
   F1[i]=b[i-2];
 }
 //Step-2: Find Transformation Matrix
 vector<vector<ll>> Tn(k+2,vector<ll>(k+2));
 vector<vector<ll>> Tm(k+2,vector<ll>(k+2));
 REP(i,1,k+2)
 {
  REP(j,1,k+2)
  {
   if(i==1)
   {
    if(j==1)
     Tn[i][j]=1;
    else
     Tn[i][j]=c[k-j+1];
   }
   else if(i==k+1)
   {
    if(j==1)
     Tn[i][j]=0;
    else
     Tn[i][j]=c[k-j+1];
   }
   else
   {
   	if(j==i+1)
   	 Tn[i][j]=1;
   	else
   	 Tn[i][j]=0;
   }
   Tm[i][j]=Tn[i][j];
  }
 }
 //Step-3: Find T^(n-1)
 Tn=pow(Tn,n-k);
 ll res1=0,res2=0;
 REP(j,1,k+2)
  res1=((res1%p)+((Tn[1][j]%p)*(F1[j]%p))%p)%p;
 if(m-k>=1)
 {
  Tm=pow(Tm,m-k-1);
  REP(j,1,k+2)
   res2=((res2%p)+((Tm[1][j]%p)*(F1[j]%p))%p)%p;
 }
 else if(m>1)
 {
  REP(i,0,m-1)
   res2+=b[i];
 }
 // cout<<res1<<endl;
 // cout<<res2<<endl;
 return (res1-res2+p)%p;
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
  cin>>m>>n>>p;
  cout<<calculate()<<endl;
  b.clear();
  c.clear();
 }
 return 0;
}