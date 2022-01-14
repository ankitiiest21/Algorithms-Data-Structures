#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;

int main()
{
 ld x=1.0;
 ll people=0;
 ld num=365,denom=365;
 ld p;
 cin>>p;
 if(p==1.0){
 	cout<<"366\n";
 	return 0;
 }
 while(x>1-p){
  x=x*(num)/denom;
  num--;
  people++;
  cout<<"People: "<<people<<", p:"<<1-x<<endl;
 }
 cout<<people<<endl;
 return 0;
}