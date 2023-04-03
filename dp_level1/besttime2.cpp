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
// void dfs(ll src, vector<bool> &vis, vector<vector<pair<ll, ll>>> &graph){
//     if(vis[src])return;
//     vis[src]=true;
//     for(ll i=0;i<graph[src].size();i++){
//         ll nbr = graph[src][i].second;
//         dfs(nbr, vis, graph);
//     }
// }
// bool isConnected(ll& n, vector<vector<pair<ll, ll>>> &graph){
//     vector<bool> vis(n, false);
//     dfs(0, vis, graph);
//     for(ll i=0;i<n;i++){
//         if(vis[i]==false){
//             return false;
//         }
//     }
//     return true;
// }
// void connect_islands(ll x, ll y, ll&n, ll&m,  vector<vector<bool>> &vis, vector<vector<ll>> &graph){
//     vector<ll> dx = {0, 0, 1, -1};
//     vector<ll> dy = {1, -1, 0, 0};
//     if(vis[x][y] || graph[x][y] == 1)return;
//     vis[x][y] = true;
//     for(ll i=0;i<4;i++){
//         ll nx = x + dx[i];
//         ll ny = y + dy[i];
//         if(nx>=0 and ny>=0 and nx<n and ny<m  and vis[nx][ny]==false and graph[nx][ny] == 0)connect(nx, ny, n, m, vis, graph);
//     }
// }
 

void solve(){
    ll n;cin>>n;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll bd = 0;
    ll sd = 0;
    ll profit = 0;
    for(ll i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            sd++;
        }else{
            profit+=arr[sd] - arr[bd];
            bd = i;
            sd = i;
        }
    }
    profit+=arr[sd] - arr[bd];
    cout<<profit<<endl;
}
int main()
{
 fast_cin();
 ll t=1;
//  cin >> t;
 for(int it=1;it<=t;it++) {
     solve();
 }
 return 0;
}