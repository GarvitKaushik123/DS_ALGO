#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define tup tuple<ll, ll, ll>
vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy = {1, -1, 0, 0};
void print(vector<ll>& arr){
    for(ll i=0;i<arr.size();i++)cout<<arr[i]<<' ';
}
ll findParent(ll x, vector<ll>& par){
    if(par[x] == -1)return x;
    return par[x] = findParent(par[x], par);
}
void Union(ll x, ll y, vector<ll>& parent, vector<ll>& rank){
    ll px = findParent(x, parent);
    ll py = findParent(y, parent);
    if(px == py)return;
    if(rank[px]>rank[py]){
        parent[py] =  px;
    }else if(rank[px]<rank[py]){
        parent[px] = py;
    }else{
        parent[py] =  px;
        rank[px]++; 
    }
}
 

void dfs(ll curr, ll cpar, ll cdisc, ll n, vector<bool>& vis, vector<bool>& ap, vector<vector<ll>>& graph, vector<ll>& par, vector<ll>& disc, vector<ll>& low){
    if(vis[curr])return;
    vis[curr] = true;
    par[curr] = cpar;
    disc[curr] = cdisc;
    low[curr] = cdisc;
    ll cnt = 0;
    for(auto nbr: graph[curr]){
        if(vis[nbr] and par[curr] == nbr){
            continue;
        }else if(vis[nbr]){
            low[curr] = min(low[curr], disc[nbr]);
        }else{
            if(curr == 0)cnt++; 
            dfs(nbr, curr, cdisc+1, n, vis, ap, graph, par, disc, low);
            low[curr] = min(low[curr], low[nbr]);
            // update ap
            if(disc[curr]<low[nbr]){
                cout<<u<<" "<<v<<endl;
            }
        }
    }

    if(cnt<=1 and curr == 0)ap[0] = false;
}

void solve(){
    ll n;cin>>n;
    ll e;cin>>e;
    vector<vector<ll>> graph(n);
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        graph[x-1].pb(y-1);
        graph[y-1].pb(x-1);
    }

    vector<bool> vis(n, false);
    vector<bool> ap(n, false);

    ll src = 0;
    vector<ll> par(n, 0);
    vector<ll> disc(n, 0);
    vector<ll> low(n, INT_MAX);
    low[0] = 0;
    dfs(src, src, 0, n, vis, ap, graph, par, disc, low);
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(ap[i])ans++;
    }
    cout<<ans<<endl;
}
int main()
{
 fast_cin();
 ll t=1;
 for(int it=1;it<=t;it++) {
     solve();
 }
 return 0;
}