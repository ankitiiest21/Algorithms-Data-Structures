#include <iostream>
using namespace std;

bool isPresent(int a[],int n,int l,int r,int key)
{
 if(l>r)
  return false;
 int mid=(l+r)/2;
 if(a[mid]>key)
  return isPresent(a,n,l,mid-1,key);
 else if(a[mid]<key)
  return isPresent(a,n,mid+1,r,key);
 else
  return true;
}

int main() {
  int n,key;
  cin>>n>>key;
  int a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];
  cout<<key<<" is "<<((isPresent(a,n,0,n-1,key))?"present":"absent")<<" in the array\n";
  return 0;   
}
