#include <iostream>
using namespace std;
void printString(int n)
{
 if(n==0)
  cout<<"Zero ";
 else if(n==1)
  cout<<"One ";
 else if(n==2)
  cout<<"Two ";
 else if(n==3)
  cout<<"Three ";
 else if(n==4)
  cout<<"Four ";
 else if(n==5)
  cout<<"Five ";
 else if(n==6)
  cout<<"Six ";
 else if(n==7)
  cout<<"Seven ";
 else if(n==8)
  cout<<"Eight ";
 else if(n==9)
  cout<<"Nine ";
}
void printSpelling(int n)
{
 //Base Case
 if(n==0)
  return;
 //Rec case to print the spelling of 204 first
 printSpelling(n/10);
 //doing work after the function call - BOTTOM UP Direction
 printString(n%10);
}
int main() {
    int n;
    cin>>n;
    printSpelling(n);
    return 0;
}
