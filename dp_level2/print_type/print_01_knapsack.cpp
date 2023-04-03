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
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vvl;
typedef vector<vector<bool> > vvb;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define fn(i,n) for(ll i = 0; i < n; i++)
#define fsn(i,s,n) for(ll i = s; i < n; i++)
#define rfn(i,n) for(ll i = n-1; i >= 0; i--)
#define rfsn(i,s,n) for(ll i = n-1; i >= s; i--)
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
    vl val(n, 0);
    fn(i, n)cin>>val[i];
    vl wt(n, 0);
    fn(i, n)cin>>wt[i];
    ll w;cin>>w;
    
    vvl dp(n+1, vl(w+1));
    fn(i, n+1){
        fn(j, w+1){
            if(i == 0 or j==0)dp[i][j] = 0;
            else{
                if(wt[i-1] <= j){
                    dp[i][j] = max( val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }else dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
    queue<tup> q;
    q.push(tup(n, w, ""));
    while(!q.empty()){
        auto rem = q.front();
        q.pop();
        ll x = get<0>(rem);
        ll y = get<1>(rem);
        string asf = get<2>(rem);
        if(x == 0 or y == 0){
            cout<<asf<<endl;
            continue;
        }
        if(wt[x-1]<=y and dp[x][y] == val[x-1] + dp[x-1][y - wt[x-1]]){
            string temp = to_string(x-1) + asf;
            q.push(tup(x-1, y-wt[x-1], temp));
        }
        if(dp[x][y] == dp[x-1][y])q.push(tup(x-1, y, asf));
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