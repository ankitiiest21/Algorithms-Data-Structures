#include <iostream>
using namespace std;

void generate_subsequences(char inp[],char out[],int i,int j)
{
 //Base case
 if(inp[i]=='\0')
 {
  out[j]='\0';
  cout<<out<<endl;
  return;
 }
 //Rec case
 //include the current character
 out[j]=inp[i];
 generate_subsequences(inp,out,i+1,j+1);
 //exclude the current character
 generate_subsequences(inp,out,i+1,j);
}

int main() {
   char inp[1000];
   cin>>inp;
   char out[1000];
   generate_subsequences(inp,out,0,0);
   return 0;
}
