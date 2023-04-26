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
bool Union(ll x, ll y, vector<ll>& parent, vector<ll>& size){
    ll px = find_leader(x, parent);
    ll py = find_leader(y, parent);
    if(px == py)return true;
    if(size[px]>size[py]){
        parent[py] =  px;
        size[px] += size[py];
    }else if(size[px]<size[py]){
        parent[px] = py;
        size[py] += size[px];
    }else{
        parent[py] =  px;
        size[px] += size[py];
    }
    return false;
}
 

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        vl size1(n, 1);
        vl size2(n, 1);
        vl par1(n, -1);
        vl par2(n, -1);
        ll red_edges = 0;
        for(ll i=0;i<edges.size();i++){
            ll type = edges[i][0];
            ll s = edges[i][1];
            ll e = edges[i][2];
            s--;e--;
            if(type == 3){
                bool op1 = Union(s, e, par2, size2);
                bool op2 = Union(s, e, par1, size1);
                if(op1 and op2)red_edges++;
            }else if(type == 2){
                if(Union(s, e, par2, size2))red_edges++;
            }else{
                if(Union(s, e, par1, size1))red_edges++;
            }
        }
        ll idx1 = find_max(size1);
        if(size1[idx1] != n)return -1;
        ll idx2 = find_max(size2);
        if(size2[idx2] != n)return -1;

        return red_edges;
    }
};


















