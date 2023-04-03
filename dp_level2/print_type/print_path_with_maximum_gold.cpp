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
#define tup tuple<ll, ll, string>
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
 

void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)cin>>arr[i][j];
    }

    for(ll j=m-1;j>=0;j--){
        for(ll i=0;i<n;i++){
            if(j == m-1)dp[i][j] = arr[i][j];
            else{
                ll ans = 0;
                if(j+1<m)ans = max(ans, dp[i][j+1]);
                if(i+1<n and j+1<m)ans = max(ans, dp[i+1][j+1]);
                if(i-1>=0 and j+1<m)ans = max(ans, dp[i-1][j+1]);
                dp[i][j] = arr[i][j] + ans; 
            }
        }
    }    

    ll x = 0;
    for(ll i=0;i<n;i++){
        if(dp[x][0]<dp[i][0])x=i;
    }

    cout<<dp[x][0]<<endl;

    queue<tup> q;
    q.push({x, 0, ""});
    while(!q.empty()){
        auto rem = q.front();
        q.pop();
        ll x = get<0>(rem);
        ll y = get<1>(rem);
        string asf = get<2>(rem);
        if(y == m-1){
            cout<<asf<<endl;
            continue;
        }
        if(y+1<m and dp[x][y] == arr[x][y] + dp[x][y+1])q.push(tup(x, y+1, asf+"d2 "));
        if(x+1<n and y+1<m and dp[x][y] == arr[x][y] + dp[x+1][y+1])q.push(tup(x+1, y+1, asf+"d3 "));
        if(x-1>=0 and y+1<m and dp[x][y] == arr[x][y] + dp[x-1][y+1])q.push(tup(x-1, y+1, asf+"d1 "));
    }
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