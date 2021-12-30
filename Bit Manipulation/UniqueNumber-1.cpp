//Given N numbers where every number is being repeated twice except one number, find that unique number.

#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

int main()
{
 ll n;
 cin>>n;
 ll no,num1=0;
 REP(i,0,n)
  cin>>no,num1^=no;
 cout<<num1<<endl;
 return 0;
}