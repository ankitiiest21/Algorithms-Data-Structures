#include <iostream>
using namespace std;

int crossInversionUsingMerge(int a[],int s,int e){
  int cnt=0;
  int mid=(s+e)/2;
  int i=s,j=mid+1,k=0;
  int temp[10000];
  while(i<=mid&&j<=e){
      if(a[i]<=a[j])
        temp[k++]=a[i++];
      else
      {
       temp[k++]=a[j++];
       cnt+=mid-i+1;
      }
  }
  while(i<=mid)
   temp[k++]=a[i++];
  while(j<=e)
   temp[k++]=a[j++];
  for(int i=s;i<=e;i++)
   a[i]=temp[i-s];
  return cnt;
}

int inversionCount(int a[],int s,int e)
{
 //Base Case
 if(s>=e)
  return 0;
 //Rec Case
 int mid=(s+e)/2;
 int x=inversionCount(a,s,mid);
 int y=inversionCount(a,mid+1,e);
 int z=crossInversionUsingMerge(a,s,e); //Cross Inversions
 return x+y+z;
}


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    cout<<inversionCount(a,0,n)<<endl;
}
