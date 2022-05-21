//Given N friends such that one friend can go to a party either as a single or as a couple. Find the number of ways such that the friends can go to a party
#include <iostream>
using namespace std;

int countWays(int n)
{
 //Base case
 if(n<=1)
  return 1;
 //Rec case
  int singleCount=countWays(n-1);
  int coupleCount=(n-1)*countWays(n-2);
  return singleCount+coupleCount;
}


int main() {
    int n;
    cin>>n;
    cout<<countWays(n)<<endl;
    return 0;
}
