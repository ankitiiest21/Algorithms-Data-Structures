#include <iostream>
using namespace std;

void towerOfHanoi(int n,char src,char helper,char dest)
{
 //Base case
 if(n==0)
  return;
 //Rec case
 //Move n-1 discs from 'A' to 'B' using 'C'
 towerOfHanoi(n-1,src,dest,helper);
 cout<<"Shift "<<n<<" disc from "<<src<<" to "<<dest<<endl;
 //move n-1 discs from 'B' to 'C' using 'A'
 towerOfHanoi(n-1,helper,src,dest);
}

int main() {
    int n;
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}
