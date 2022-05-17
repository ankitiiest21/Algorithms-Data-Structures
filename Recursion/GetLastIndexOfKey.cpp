#include <iostream>
using namespace std;

int linearSearch(int*a,int n,int key){
    if(n==0)
      return -1;
    int i=linearSearch(a+1,n-1,key);
    if(i==-1)
    {
     if(a[0]==key)
      return 0;
     else
      return -1;
    }
     return i+1;
}

int getLastIndex(int a[],int n,int ind,int key){
    if(ind>=n)
     return -1;
    if(a[ind]==key)
     return max(ind,getLastIndex(a,n,ind+1,key));
    return getLastIndex(a,n,ind+1,key);
}
int main() {
    int n,key;
    cin>>n>>key;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    int ans=getLastIndex(a,n,0,key);
    if(ans!=-1)
     cout<<key<<" is occuring lastly at the index "<<ans<<endl;
    else
     cout<<key<<" is not present in the array\n";
    ans=linearSearch(a,n,key);
    if(ans!=-1)
     cout<<key<<" is occuring lastly at the index "<<ans<<endl;
    else
     cout<<key<<" is not present in the array\n";
    return 0;
}
