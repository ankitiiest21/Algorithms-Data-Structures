#include <iostream>
using namespace std;

void generate_strings(char inp[],char out[],int i,int j)
{
 //Base case
 if(inp[i]=='\0')
 {
  out[j]='\0';
  cout<<out<<endl;
  return;
 }
 //Rec case
 int digit1=inp[i]-'0';
 if(digit1!=0)
 {
  //Current digit is non-zero
//   cout<<"Current digit is "<<digit1<<endl;
  out[j]=digit1+'A'-1;
  if(inp[i+1]!='\0')
  {
   int digit2=inp[i+1]-'0';
   int curr=digit1*10+digit2;
   if(digit2!=0)
   {
    //Both Current and Next digit is non-zero
    // cout<<"Next digit is "<<digit2<<endl;
    // cout<<"Calling function with current alphabet -"<<out[j]<<"\n";
    generate_strings(inp,out,i+1,j+1);
    if(curr<=26)
    {
     //Including both current and next digit is feasible
     out[j]='A'+curr-1;
    //  cout<<"Calling function with current alphabet -"<<out[j]<<"\n";
     generate_strings(inp,out,i+2,j+1);
    }
   }
   else
   {
    //Current digit is non-zero while next digit is zero. 
    //Next digit must be included with current digit(if feasible) otherwise ignored
    if(curr<=26)
    {
     out[j]='A'+curr-1;
    //  cout<<"Calling function with current alphabet -"<<out[j]<<"\n";
     generate_strings(inp,out,i+2,j+1);
    }
    else{
        // cout<<"Calling function with current alphabet -"<<out[j]<<"\n";
        generate_strings(inp,out,i+2,j+1);
    }
   }
  }
  else{
        // cout<<"Calling function with current alphabet -"<<out[j]<<"\n";
        generate_strings(inp,out,i+1,j+1);
    }
 }
 else{
//   cout<<"Ignoring current digit\n";
  generate_strings(inp,out,i+1,j);
 }
  
 return;
}

int main() {
    char inp[1000];
    cin>>inp;
    char out[1000];
    generate_strings(inp,out,0,0);
    return 0;
}
