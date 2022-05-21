#include <iostream>
using namespace std;

int countWaysToReachNthStep(int n)
{
 //Base case
 if(n<0)
  return 0;
 if(n<=1)
  return 1;
 //Rec case
 return countWaysToReachNthStep(n-1)+countWaysToReachNthStep(n-2)+countWaysToReachNthStep(n-3);
}

int countWaysToReachNthStepWithMaxKjumps(int n,int k)
{
 //Base case
 if(n<0)
  return 0;
 if(n<=1)
  return 1;
 //Rec case
 int ans=0;
 for(int i=1;i<=k;i++)
  ans+=countWaysToReachNthStepWithMaxKjumps(n-i,k);
 return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<countWaysToReachNthStep(n)<<endl;
    cout<<countWaysToReachNthStepWithMaxKjumps(n,k)<<endl;
    return 0;
}
