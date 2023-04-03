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

vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy = {1, -1, 0, 0}; 

void dfs(ll r, ll c, ll& tlr, ll& tlc, vector<vector<bool>>& vis, vector<vector<ll>>& arr, string& s){
    vis[r][c] = true;
    ll mr = r - tlr;
    ll mc = c - tlc;
    s+=to_string(mc + mr*(arr[0].size()));
    // cout<<" : "<<s<<endl;
    for(ll i=0;i<4;i++){
        ll nr = r + dx[i];
        ll nc = c + dy[i];
        if(nr<0 or nc<0 or nr>=arr.size() or nc>=arr[0].size() or vis[nr][nc] or (arr[nr][nc] == 0))continue;
        dfs(nr, nc, tlr, tlc, vis, arr, s);
    }
}

void solve(){
    ll m;cin>>m;
    ll n;cin>>n;
    vector<vector<ll>> arr(m, vector<ll>(n, 0));
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++)cin>>arr[i][j];
    }
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    set<string> s;
    ll count = 0;

    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            if(arr[i][j] == 1 and !vis[i][j]){
                string x = "";
                // cout<<i<<j<<endl;
                dfs(i, j, i, j, vis, arr, x);
                if(s.find(x) != s.end())continue;
                s.insert(x);
                count++;
                // cout<<"x "<<x<<endl;
            }
        }
    }
    cout<<count<<endl;
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