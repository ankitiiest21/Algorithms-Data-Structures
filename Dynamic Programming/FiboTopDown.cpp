#include<bits/stdc++.h>
#include<iostream>
long long dp[100007]={0};
using namespace std;

long long fib(int n)
{
 //Base Condition
 if(n==0 or n==1)
  return n;
 //Look Up
 if(dp[n]!=0)
  return dp[n];
 long long ans=fib(n-1)+fib(n-2);
 return dp[n]=ans;
}

int main()
{
 int n;
 cin>>n;
 cout<<fib(n)<<endl;
 return 0;
}