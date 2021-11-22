#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;


int main()
{
 ll n,k,extras=0;
 cin>>n>>k;
 char c;
 ll mat[n+1][n+1];
 REP(i,1,n+1)
 {
  REP(j,1,n+1)
  {
   cin>>c;
   if(c=='B')
   	mat[i][j]=1;
   else
   	mat[i][j]=0;
  }
 }
 ll sufr[n+1][n+1],sufc[n+1][n+1],posr[n+1][n+1],posc[n+1][n+1];
 REP(i,0,n+1)
 {
   mat[i][0]=0;
   mat[0][i]=0;
   sufr[i][0]=0;
   sufr[0][i]=0;
   sufc[i][0]=0;
   sufc[0][i]=0;
 }
 REP(i,1,n+1)
 {
  REP(j,1,n+1)
  {
   sufr[i][j]=sufr[i][j-1]+mat[i][j];
   sufc[j][i]=sufc[j-1][i]+mat[j][i];
  }
 }
 REP(i,0,n+1)
 {
  ll rowTotal=sufr[i][n];
  REP(j,0,n+1)
  {
   if(rowTotal==0)
   	extras++;
   posr[i][j]=0;
   ll winBorder=max(0ll,j-k);
   if(rowTotal!=0&&sufr[i][j]-sufr[i][winBorder]==rowTotal)
   	posr[i][j]=1;
  }
 }
 REP(i,0,n+1)
 {
  REP(j,0,n+1)
  {
   ll colTotal=sufc[n][j];
   if(colTotal==0)
   	extras++;
   posc[i][j]=0;
   ll winBorder=max(0ll,i-k);
   if(colTotal!=0&&sufc[i][j]-sufc[winBorder][j]==colTotal)
   	posc[i][j]=1;
  } 
 }
 extras/=(n+1);
 memset(sufr,0,sizeof(sufr));
 memset(sufc,0,sizeof(sufc));
 REP(i,0,n+1)
 {
  sufr[i][0]=posc[i][0];
  sufr[0][i]=posc[0][i];
  sufc[i][0]=posr[i][0];
  sufc[0][i]=posr[0][i];
 }
 REP(i,1,n+1)
 {
  REP(j,1,n+1)
  {
   sufr[i][j]=sufr[i][j-1]+posc[i][j];
   sufc[j][i]=sufc[j-1][i]+posr[j][i];
  }
 }
 ll ans=0,tempans=0;
 REP(i,0,n+1)
 {
  REP(j,0,n+1)
  {
   ll rowBorder=max(0ll,j-k);
   ll colBorder=max(0ll,i-k);
   tempans=0;
   tempans+=sufr[i][j]-sufr[i][rowBorder];
   tempans+=sufc[i][j]-sufc[colBorder][j];
   ans=max(ans,tempans);
  }
 }
 cout<<ans+extras-2<<endl;
}