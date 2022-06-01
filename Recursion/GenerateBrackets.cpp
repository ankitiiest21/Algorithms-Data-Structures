#include <iostream>
using namespace std;

void generate_brackets(char out[],int n,int ind,int cntOpen,int cntClose)
{
 //Base case
 if(ind==2*n)
 {
  out[ind]='\0';
  cout<<out<<endl;
  return;
 }
 //Rec case
 //1. Put an opening bracket
 if(cntOpen<n)
 {
  out[ind]='(';
  generate_brackets(out,n,ind+1,cntOpen+1,cntClose);
 }
 //2. Put a closing bracket
 if(cntClose<cntOpen)
 {
  out[ind]=')';
  generate_brackets(out,n,ind+1,cntOpen,cntClose+1);
 }
 return;
}

int main() {
    int n;
    cin>>n;
    char out[10000];
    generate_brackets(out,n,0,0,0);
}
