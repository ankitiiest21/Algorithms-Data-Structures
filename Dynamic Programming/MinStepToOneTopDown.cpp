#include<bits/stdc++.h>
#include<iostream>
long long dp[100007]={0};
using namespace std;

long long minStepToOne(int n)
{
 if(n==1)
  return 0;
 if(dp[n]!=0)
  return dp[n];
 long long ans=INT_MAX;
 if(n%3==0)
  ans=min(ans,minStepToOne(n/3)+1);
 if(n%2==0)
  ans=min(ans,minStepToOne(n/2)+1);
 if(n>1)
  ans=min(ans,minStepToOne(n-1)+1);
 return dp[n]=ans;
}

int main()
{
 int n;
 cin>>n;
 cout<<minStepToOne(n)<<endl;
 return 0;
}