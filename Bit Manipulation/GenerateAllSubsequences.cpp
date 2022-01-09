#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

void filterChars(string s,ll n)
{
 ll i=0;
 while(n>0)
 {
  ll last_bit=(n&1);
  if(last_bit)
    cout<<s[i];
  i++;
  n>>=1;
 }
 cout<<endl;
}

void printSubsequences(string s)
{
 ll n=s.length();
 REP(i,0,(1<<n))
  filterChars(s,i);
 return;
}

int main()
{
 string s;
 cin>>s;
 printSubsequences(s);
 return 0;
}