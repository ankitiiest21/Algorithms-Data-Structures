//https://www.spoj.com/problems/HOLI/
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define mod 1000000007
#define MAXI 10000000000
using namespace std;
vector<pair<ll,ll>> graph[100009];
ll subTreeSize[100009],n;
vector<bool> vis(100009)
ll dfsUtil(ll node,ll &ans)
{
 vis[node]=true;
 subTreeSize[node]=1;
 for(auto edge:graph[node])
 {
  ll child=edge.first;
  ll weight=edge.second;
  if(!vis[child])
  {
   subTreeSize[node]+=dfsUtil(child,ans);
   ans+=2*min(subTreeSize[child],n-subTreeSize[child])*weight;
  }
 }
 return subTreeSize[node];
}

ll dfs()
{
 ll ans=0;
 ll res=dfsUtil(1,ans);
 return ans;
}

int main()
{
  ll t=1;
  cin>>t;
  REP(T,1,t+1)
  {
   ll a,b,w;
   cin>>n;
   REP(i,1,n+1)
    graph[i].clear(),subTreeSize[i]=0,vis[i]=false,subTreeSize[i]=0;
   REP(i,0,n-1)
   {
    cin>>a>>b>>w;
    graph[a].PB({b,w});
    graph[b].PB({a,w});
   }
   cout<<"Case #"<<T<<": "<<dfs()<<endl;
  }
   return 0;
}
