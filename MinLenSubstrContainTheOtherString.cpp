#include<iostream>
#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<limits.h>
#include<string>
#include<map>
#include<time.h>
#include<queue>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define PF push_front
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long
#define ld long double
#define pl pair<ll,ll>
#define ql queue<ll>
#define dql deque<ll>
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vc vector<char>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define ADD(a,sum) accumulate(a.begin(),a.end(),sum)
#define REV(a) reverse(a.begin(),a.end())
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)51
#define INF (ll)10000000000
#define mod (ll)1000000007 
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> pbdsm;



int main()
{
 #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  ll t=1;
  // pbdsm stm;
  // cin>>t;
  REP(i,1,t+1)
  {
   string s,t;
   getline(cin,s);
   getline(cin,t);
   ll n=s.size(),m=t.size();
   ll l=0,r=0,ansl=0,ansr=1e9;
   map<char,int> freq_s,freq_t;
   for(auto i:t)
    freq_t[i]++;
   REP(r,0,n)
   {
    freq_s[s[r]]++;
    bool good=true;
    for(auto x:freq_t){
      if((freq_s.count(x.first)==0)||freq_s[x.first]<x.second){
         good=false;
         break;
      }
    }
    if(!good)
      continue;
    while(l<n&&l<=r&&(freq_t.count(s[l])==0||freq_s[s[l]]>freq_t[s[l]]))
    {
     freq_s[s[l]]--;
     if(freq_s[s[l]]==0)
       freq_s.erase(s[l]);
     l++;
    }
    // cout<<l<<" "<<r<<endl;
    if(ansr-ansl+1>r-l+1)
      ansr=r,ansl=l;
   }
   REP(i,ansl,ansr+1)
    cout<<s[i];
   cout<<endl;
  }
  return 0;
}



