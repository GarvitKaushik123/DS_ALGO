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
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vvl;
typedef vector<vector<bool>> vvb;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define fn(i, n) for (ll i = 0; i < n; i++)
#define fsn(i, s, n) for (ll i = s; i < n; i++)
#define rfn(i, n) for (ll i = n - 1; i >= 0; i--)
#define rfsn(i, s, n) for (ll i = n - 1; i >= s; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define tup tuple<ll, ll, ll>
vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy = {1, -1, 0, 0};
ll find_max(vl &arr) { return max_element(arr.begin(), arr.end()) - arr.begin(); }
ll find_min(vl &arr) { return min_element(arr.begin(), arr.end()) - arr.begin(); }
void print(vector<ll> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}
bool isPalin(string s)
{
    if (s.size() == 0 or s.size() == 1)
        return true;
    return (s[0] == s[s.size() - 1]) and isPalin(s.substr(1, s.size() - 2));
}
vl prefix_sum(vl &arr)
{
    ll n = arr.size();
    vl ps(n, 0);
    ps[0] = arr[0];
    fsn(i, 1, n) ps[i] = ps[i - 1] + arr[i];
    return ps;
}
vl suffix_sum(vl &arr)
{
    ll n = arr.size();
    vl ss(n, 0);
    ss[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; i--)
        ss[i] = ss[i + 1] + arr[i];
    return ss;
}
ll findParent(ll x, vector<ll> &par)
{
    if (par[x] == -1)
        return x;
    return par[x] = findParent(par[x], par);
}
void Union(ll x, ll y, vector<ll> &parent, vector<ll> &rank)
{
    ll px = findParent(x, parent);
    ll py = findParent(y, parent);
    if (px == py)
        return;
    if (rank[px] > rank[py])
    {
        parent[py] = px;
    }
    else if (rank[px] < rank[py])
    {
        parent[px] = py;
    }
    else
    {
        parent[py] = px;
        rank[px]++;
    }
}

    bool scramble(string src, string tar, map<pair<string, string>, ll>& mp)
    {
        if(mp[{src, tar}] != 0){
            if(mp[{src, tar}] == 1)return true;
            else return false;
        }
        ll n = src.size();
        if (n != tar.size())
            return false;
        if (n == 1)
        {
            if (src == tar)
                return true;
            return false;
        }
        if (src == tar)
            return true;
        for (ll k = 1; k <= n - 1; k++)
        {
            bool cond1 = scramble(src.substr(0, k), tar.substr(0, k), mp) and scramble(src.substr(k, n - k), tar.substr(k, n - k), mp);
            bool cond2 = scramble(src.substr(0, k), tar.substr(n - k, k), mp) and scramble(src.substr(k, n - k), tar.substr(0, n - k), mp);
            if (cond1 or cond2){
                mp[{src, tar}] = 1;
                return true;
            }
        }
        mp[{src, tar}] = 2;
        return false;
    }

void solve()
{
    string src;
    cin >> src;
    string tar;
    cin >> tar;
    map<pair<string, string>, ll> mp;
    ll n = src.size();
    if (n != tar.size()){
        return false;
    }

    bool ans = scramble(src, tar, mp);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
int main()
{
    fast_cin();
    ll t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}