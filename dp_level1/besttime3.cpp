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
void print(vector<ll>& arr){
    for(ll i=0;i<arr.size();i++)cout<<arr[i]<<' ';
}
void dfs(ll src, vector<bool> &vis, vector<vector<pair<ll, ll>>> &graph){
    if(vis[src])return;
    vis[src]=true;
    for(ll i=0;i<graph[src].size();i++){
        ll nbr = graph[src][i].second;
        dfs(nbr, vis, graph);
    }
}



void solve(){
    ll n;cin>>n;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++)cin>>arr[i];

    // stage 1
    vector<ll> pre_min(n, 0);
    pre_min[0] = arr[0];
    for(ll i=1;i<n;i++)pre_min[i] = min(pre_min[i-1], arr[i]);
    vector<ll> first(n, 0);
    for(ll i=1;i<n;i++)first[i] = max(first[i-1], arr[i] - pre_min[i]);
    // stage 2
    vector<ll> suf_max(n, 0);
    suf_max[n-1] = arr[n-1];
    for(ll i=n-2;i>=0;i--)suf_max[i] = max(suf_max[i+1], arr[i]);
    vector<ll> second(n, 0);
    for(ll i=n-2;i>=0;i--){
        second[i] = suf_max[i] - arr[i];
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans = max(ans, first[i] + second[i]);
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