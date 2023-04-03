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
void print(vector<ll> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
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

void solve()
{
    string str;
    cin >> str;
    string opr;
    cin >> opr;

    ll n = str.size();
    vvl dp_true(n, vl(n, 0));
    vvl dp_false(n, vl(n, 0));

    for(ll g=0;g<n;g++){
        for(ll i=0,j=g;j<n;i++,j++){
            if(g == 0){
                dp_true[i][j] = (str[i] == 'T')?1:0;
                dp_false[i][j] = (str[i] == 'F')?1:0;
            }else{
                for(ll k=i;k<=j-1;k++){
                    char op = opr[k];
                    // cout<<op<<endl;
                    if(op == '&'){
                        dp_true[i][j] = dp_true[i][k] * dp_true[k+1][j];
                        dp_false[i][j] = (dp_true[i][k] * dp_false[k+1][j]) + (dp_false[i][k] * dp_false[k+1][j]) + (dp_false[i][k] * dp_true[k+1][j]);
                    }else if(op == '|'){
                        dp_true[i][j] = (dp_true[i][k] * dp_false[k+1][j]) + (dp_true[i][k] * dp_true[k+1][j]) + (dp_false[i][k] * dp_true[k+1][j]);
                        dp_false[i][j] = dp_false[i][k] * dp_false[k+1][j];
                    }else{
                        dp_true[i][j] = (dp_true[i][k] * dp_false[k+1][j]) + (dp_false[i][k] * dp_true[k+1][j]);
                        dp_false[i][j] =  (dp_false[i][k] * dp_false[k+1][j]) +  (dp_true[i][k] * dp_true[k+1][j]);
                    }
                }
            }
        }
    }

    cout<<dp_true[0][n-1]<<endl;
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