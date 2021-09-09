#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long long minStepToOne(int n)
{
 //Base Condition
 if(n==1)
  return 0;
 long long ans=INT_MAX;
 if(n%3==0)
  ans=min(ans,minStepToOne(n/3)+1);
 if(n%2==0)
  ans=min(ans,minStepToOne(n/2)+1);
 if(n>1)
  ans=min(ans,minStepToOne(n-1)+1);
 return ans;
}

int main()
{
 int n;
 cin>>n;
 cout<<minStepToOne(n)<<endl;
 return 0;
}