#include <iostream>
using namespace std;

int partition(int a[],int s,int e)
{
 //Inplace (taking extra array is not allowed)
 int i=s-1,j=s; //index i will determine the region-1(elements which are smaller than or equal to pivot)
 int p=a[e]; //taking pivot as the last element
 for(;j<e;)
 {
  if(a[j]<=p)
  {
   //merge the smaller element in the region-1
   i=i+1;
   swap(a[i],a[j]);
  }
  //expand the larger region
  j++;
 }
 //placing the pivot element in the correct position
 swap(a[e],a[i+1]);
 return i+1;
}

void quickSort(int a[],int s,int e)
{
 //Rec case
 if(s>=e)
  return;
 int pivot=partition(a,s,e);
 //After partition is called,pivot element will be at the correct position
 quickSort(a,s,pivot-1);
 quickSort(a,pivot+1,e);

}

int main() {
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   quickSort(a,0,n-1);
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
   cout<<endl;
   return 0;
}
