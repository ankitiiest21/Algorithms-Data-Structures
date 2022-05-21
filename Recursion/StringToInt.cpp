#include <iostream>
using namespace std;
int stringtoInt(string s,int ind,int placeval){
  //Base Case
  if(ind<0)
   return 0;
 //Rec case
  int res=stringtoInt(s,ind-1,placeval*10);
  res=placeval*(s[ind]-'0')+res;
  return res;
} 

int string_to_int(string s,int n)
{
 //Base case
 if(n==0)
  return 0;
 //Rec case
 int digit=s[n-1]-'0';
 int small_ans=string_to_int(s,n-1);
 return small_ans*10+digit;
}


int main() {
    string s;
    cin>>s;
    cout<<stringtoInt(s,s.size()-1,1)<<endl;
    cout<<string_to_int(s,s.size())<<endl;
    return 0;
}
