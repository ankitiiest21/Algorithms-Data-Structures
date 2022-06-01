#include <iostream>
using namespace std;

int maxProfit(int wt[],int price[],int n,int capacity)
{
 //Base case
 if(n==0||capacity==0)
  return 0;
 //Rec case
 int inc,exc;
 inc=exc=0;
 //1. Include the current item
 if(wt[n-1]<=capacity)
  inc=price[n-1]+maxProfit(wt,price,n-1,capacity-wt[n-1]);
 //2. Exclude the current item
 exc=maxProfit(wt,price,n-1,capacity);
 return max(inc,exc);
}

int main() {
    int n,capacity;
    cin>>n>>capacity;
    int wt[n],price[n];
    for(int i=0;i<n;i++)
     cin>>wt[i];
    for(int i=0;i<n;i++)
     cin>>price[i];
    cout<<maxProfit(wt,price,n,capacity)<<endl;
    return 0;
}
