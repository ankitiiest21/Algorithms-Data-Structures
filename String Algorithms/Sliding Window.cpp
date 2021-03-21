#include<iostream>
#include<bits/stdc++.h> 

using namespace std;
string P,T;
int NP,NT;
bool match(int l,int r){
  for(int i=0;i<NP;i++)
    if(T[l+i]!=P[i])
      return false;
  return true;
}

int main()
{
  int t;
  cin>>t;
  cin.ignore();
  while(t--){
    getline(cin,T);
    getline(cin,P);
    NP=P.size();
    NT=T.size();
    for(int l=0,r=NP-1;r<NT;l++,r++)
      if(match(l,r))
        cout<<l<<" ";
    cout<<"\n";
  }
  return 0;
}