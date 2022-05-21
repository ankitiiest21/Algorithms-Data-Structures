//Find the number of binary strings of length N with no consecutive 1's
#include <iostream>
using namespace std;

int countBinaryStrings(int n)
{
 //Base case
 if(n<=1)
  return n+1;
 //Rec case
 int currCharAsZero = countBinaryStrings(n-1);
 int currCharAsOne = countBinaryStrings(n-2);
 return currCharAsOne+currCharAsZero;
}

int main() {
    int n;
    cin>>n;
    cout<<countBinaryStrings(n)<<endl;
    return 0;
}
