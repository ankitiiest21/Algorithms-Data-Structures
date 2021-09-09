#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int fib(int n)
{
 //Base Case
 if(n==0 or n==1)
  return n;
 int ans=fib(n-1)+fib(n-2);
 return ans;
}

int main()
{
 int n;
 cin>>n;
 cout<<fib(n)<<endl;
 return 0;
}
