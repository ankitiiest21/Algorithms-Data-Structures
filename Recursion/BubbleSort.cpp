#include <iostream>
using namespace std;

void bubbleSort(int a[],int n){
  //Base case
  if(n==1)
   return;
  //Rec case
  //Moving the largest element to the end of the current array by pairwise swapping
  for(int j=0;j<n-1;j++)
  {
   if(a[j]>a[j+1])
    swap(a[j],a[j+1]);
  }
  //sort the first n-1 elements
  bubbleSort(a,n-1);
}

void bubbleSortRecursive(int a[],int j,int n){
    //Base Case
    if(n==1)
     return;
    if(j==n-1)
    {
     //single pass of the array is done
     return bubbleSortRecursive(a,0,n-1);
    }
    //Rec case
    if(a[j]>a[j+1])
     swap(a[j],a[j+1]);
    return bubbleSortRecursive(a,j+1,n);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    bubbleSortRecursive(a,0,n);
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
    return 0;
}
