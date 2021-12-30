//Given N numbers where every number is being repeated twice except two numbers, find those unique two numbers.

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
 ll a[n],xorRes=0,num1=0,num2;
 REP(i,0,n)
  cin>>a[i],xorRes^=a[i];
 ll mask=1;
 //Find the position of the first set bit in the xorRes.
 while(mask&xorRes==0)
  mask=mask<<1;
 //Iterate through the elements and take the XOR of the elements having set bit in the above found position.
 //Resultant XOR of the favourable elements will be the num1.
 REP(i,0,n)
 {
  if(mask&a[i])
  	num1^=a[i];
 }
 //Find num2 by XORing xorRes with num1.
 num2=num1^xorRes;
 cout<<min(num1,num2)<<" "<<max(num1,num2)<<endl;
 return 0;
}