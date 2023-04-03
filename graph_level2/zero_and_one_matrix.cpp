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
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
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
void print(vector<ll> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}

class unit
{
public:
    ll x;
    ll y;
    ll level;
    unit(ll x, ll y, ll level)
    {
        this->x = x;
        this->y = y;
        this->level = level;
    }
};
vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

struct cmp
{
    bool operator()(unit &a, unit &b)
    {
        if (a.level > b.level)
            return true;
        else
            return false;
    }
};

void
solve()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> vis(n, vector<ll>(m, -1));
    queue<unit> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                q.push(unit(i, j, 0));
            }
        }
    }
    while (!q.empty())
    {
        unit rem = q.front();
        q.pop();
        ll x = rem.x;
        ll y = rem.y;
        ll level = rem.level;
        if(vis[x][y] != -1)continue;
        vis[x][y] = level;
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or (vis[nx][ny] != -1))
                continue;
            else q.push(unit(nx, ny, level + 1));
        }
    }
    for (ll i = 0; i < n; i++)
    {
        print(vis[i]);
        cout << endl;
    }
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