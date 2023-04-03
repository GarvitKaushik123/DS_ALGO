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
 
void dfs(ll curr, stack<ll>& st, vector<bool>&vis, vector<vector<ll>>& graph){
    if(vis[curr])return;
    vis[curr] = true;
    for(ll i=0;i<graph[curr].size();i++){
        if(!vis[graph[curr][i]])dfs(graph[curr][i], st, vis, graph);
    }
    st.push(curr);
}

void solve(){ 
    ll n;cin>>n;
    ll e;cin>>e;
    vector<vector<ll>> graph(n);
    vector<vector<ll>> n_graph(n);

    for(ll i=0;i<e;i++){
        ll x,y;cin>>x>>y;
        x--;y--;
        graph[x].push_back(y);
        n_graph[y].push_back(x);
    }

    // dfs from random point
    stack<ll> st;
    vector<bool> vis(n, false);
    for(ll i=0;i<n;i++){
        if(vis[i] == false)dfs(i, st, vis, graph);
    }

    // reverse the graph

    // iterate stack and dfs
    ll cnt = 0;
    stack<ll> n_st;
    vector<bool> n_vis(n, false);
    while(!st.empty()){
        auto rem = st.top();
        st.pop();
        if(n_vis[rem]){
            continue;
        }else{
            cnt++;
            dfs(rem, n_st, n_vis, n_graph);
        }
    }
    cout<<cnt<<endl;
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