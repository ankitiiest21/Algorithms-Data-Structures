#include<bits/stdc++.h>
#include<iostream>


using namespace std;

long long getMaxProfitBySellWines(int price[],int n,int l,int r,int y)
{
 if(l>r)
  return 0;
 return max(price[l]*y+getMaxProfitBySellWines(price,n,l+1,r,y+1),price[r]*y+getMaxProfitBySellWines(price,n,l,r-1,y+1));
}

int main()
{
 int n;
 cin>>n;
 int price[n];
 for(int i=0;i<n;i++)
  cin>>price[i];
 cout<<getMaxProfitBySellWines(price,n,0,n-1,1)<<endl;
 return 0;
}