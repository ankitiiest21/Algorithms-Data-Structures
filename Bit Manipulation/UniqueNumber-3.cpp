//Given N numbers where every number is being repeated thrice except one number, find that unique number.

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
 //Since all the numbers except one occurs thrice, for every bit position,the sum of set bits can be of the form 3N or 3N+1.
 //3N when there is no set bit at the position in the unique number.
 //3N+1 when there is a set bit at the position in the unique number. 
 ll freqSetBits[64]={0},num,ans=0,p=1;
 REP(i,0,n)
 {
  cin>>num;
  ll j=0;
  while(num>0)
  {
    freqSetBits[j]+=(num&1);
    j++;
    num=num>>1;
  }
 }
 REP(i,0,64)
  freqSetBits[i]%=3;
 //Calculating ans from the freqSetBits which contain the ans in binary format.
 REP(i,0,64)
 {
  ans+=(freqSetBits[i]*p);
  p=p<<1;
 }
 cout<<ans<<endl;
 return 0;
}