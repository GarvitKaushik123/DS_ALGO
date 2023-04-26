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
bool isPalin(string s){if(s.size() == 0 or s.size() == 1)return true;return (s[0] == s[s.size()-1]) and isPalin(s.substr(1, s.size()-2));}
vl prefix_sum(vl& arr){ll n = arr.size();vl ps(n, 0);ps[0] = arr[0];fsn(i, 1, n)ps[i] = ps[i-1] + arr[i];return ps;}
vl suffix_sum(vl& arr){ll n = arr.size();vl ss(n, 0);ss[n-1] = arr[n-1];for(ll i=n-2;i>=0;i--)ss[i] = ss[i+1] + arr[i];return ss;}
ll find_leader(ll x, vector<ll>& par){
    if(par[x]<0)return x;
    return par[x] = find_leader(par[x], par);
}
 
class Solution {
public:
    class unit{
        public:
            ll r;
            ll c;
            ll val;
        unit(ll r, ll c, ll val){
            this->r = r;
            this->c = c;
            this->val = val;
        }
    };

    static bool cmp(unit& a, unit& b){
        return a.val<b.val;
    }

    void process(vector<unit>& to_process, vvl& mat, vl& row, vl& col){
        ll n = mat.size();
        ll m = mat[0].size();
        vl par(n+m, -1);
        fn(i, to_process.size()){
            ll r = to_process[i].r;
            ll c = to_process[i].c;
            ll px = find_leader(r, par);
            ll py = find_leader(c+n, par);

            // available options for ranks
            ll op1 = row[r]+1;
            ll op2 = col[c]+1;
            ll op3 = -1*par[px]; 
            ll op4 = -1*par[py];
            ll mx = max({op1, op2, op3, op4});
            par[py] = px;
            par[px] = -1*mx;
        }

        fn(i, to_process.size()){
            ll r = to_process[i].r;
            ll c = to_process[i].c;
            ll lr = find_leader(r, par);
            mat[r][c] = -1*par[lr];
            row[r] = -1*par[lr];
            col[c] =-1*par[lr];
        }

    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        ll n = mat.size();
        ll m = mat[0].size();
        vector<unit> arr;
        fn(i, n)fn(j, m)arr.pb(unit(i, j, mat[i][j]));
        sort(arr.begin(), arr.end(), cmp);

        vl row(n, 0);
        vl col(m, 0);
        vector<unit> to_process;
        ll latest = INT_MIN;
        fn(i, n*m){
            ll cval = arr[i].val;
            if(latest!=cval){
                process(to_process, mat, row, col);
                latest = cval;
                to_process.clear();
            }
            to_process.pb(arr[i]);
        }
        process(to_process, mat, row, col);
        return mat;
    }
};


















