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
 
typedef int ll;
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
#define tup tuple<ll, ll, ll>
vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy = {1, -1, 0, 0};
ll find_max(vl& arr){return max_element(arr.begin(), arr.end()) - arr.begin();}
ll find_min(vl& arr){return min_element(arr.begin(), arr.end()) - arr.begin();}
void print(vector<ll>& arr){for(ll i=0;i<arr.size();i++)cout<<arr[i]<<' ';}
bool isPalin(string s){if(s.size() == 0 or s.size() == 1)return true;return (s[0] == s[s.size()-1]) and isPalin(s.substr(1, s.size()-2));}
vl prefix_sum(vl& arr){ll n = arr.size();vl ps(n, 0);ps[0] = arr[0];fsn(i, 1, n)ps[i] = ps[i-1] + arr[i];return ps;}
vl suffix_sum(vl& arr){ll n = arr.size();vl ss(n, 0);ss[n-1] = arr[n-1];for(ll i=n-2;i>=0;i--)ss[i] = ss[i+1] + arr[i];return ss;}
ll find_leader(ll x, vector<ll>& par){
    if(par[x] == -1)return x;
    return par[x] = find_leader(par[x], par);
}
bool Union(ll x, ll y, vector<ll>& parent, vector<ll>& rank){
    ll px = find_leader(x, parent);
    ll py = find_leader(y, parent);
    if(px == py)return true;
    if(rank[px]>rank[py]){
        parent[py] =  px;
    }else if(rank[px]<rank[py]){
        parent[px] = py;
    }else{
        parent[py] =  px;
        rank[px]++;
    }
    return false;
}

ll cycle_detection(vector<vector<int>>& edges, ll bl){
    ll n = edges.size();
    vl par(n, -1);
    vl rank(n, 1);
    fn(i, edges.size()){
        if(bl==i)continue;
        ll src = edges[i][0];
        ll dest = edges[i][1];
        src--;dest--;
        if(Union(src, dest, par, rank))return i;
    }
    return -1;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        ll n = edges.size();
        // multiple parent check 
        vl indegree(n, -1);
        ll bl1 = -1;
        ll bl2 = -1;
        fn(i, edges.size()){
            ll src = edges[i][0];
            ll dest = edges[i][1];
            src--;dest--;
            if(indegree[dest] != -1){
                bl1 = i;
                bl2 = indegree[dest];
                break;
            }else{
                indegree[dest] = i;
            }
        }

        // cycle check using dsu
        if(bl1==-1)return edges[cycle_detection(edges, -1)];
        ll ans1 = cycle_detection(edges, bl1);
        if(ans1 == -1)return edges[bl1];
        ll ans2 = cycle_detection(edges, bl2);
        if(ans2 == -1)return edges[bl2];
        return edges[bl1];
    }
};


















