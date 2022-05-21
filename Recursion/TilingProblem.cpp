#include <iostream>
using namespace std;
int countWaysToPlaceTiles(int n)
{
 //Base Case
 if(n<=3)
  return 1;
 //Rec case
 return countWaysToPlaceTiles(n-1)+countWaysToPlaceTiles(n-4);
}
int main() {
    int n;
    cin>>n;
    cout<<countWaysToPlaceTiles(n)<<endl;
    return 0;
}
