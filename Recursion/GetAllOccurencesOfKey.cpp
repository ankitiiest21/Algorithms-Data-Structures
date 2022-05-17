#include <iostream>
using namespace std;


void getAllOccurences(int a[],int n,int ind,int key){
    if(ind>=n)
     return;
    if(a[ind]==key)
     cout<<ind<<" ";
    getAllOccurences(a,n,ind+1,key);
}

int main() {
    int n,key;
    cin>>n>>key;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    cout<<key<<" is occuring at position(s): ";
    getAllOccurences(a,n,0,key);
    cout<<endl;
    return 0;
}
