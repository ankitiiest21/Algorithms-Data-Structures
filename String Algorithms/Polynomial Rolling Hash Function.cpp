#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
using namespace std;

ll calculate_hash(string const&s){
  ll p=31;
  ll m=1e9+9;
  ll p_pow=1;
  ll hash=0;
  for(char c:s){
    hash=(hash+p_pow*(c-'a'+1))%m;
    p_pow=(p_pow*p)%m;
  }
  return hash;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    //constraining s to contain only lowercase letters
    string s;
    cin>>s;
    cout<<calculate_hash(s)<<endl;
  }
  return 0;
}
