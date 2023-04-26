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

class Solution {
public:
    vl hash;
    vl power;
    ll mod = 1e9+7;
    ll r = 256;
    void rolling_hash(string str, ll n){
        hash = vl(n, 0);
        power = vl(n, 0);
        power[0] = 1;
        fsn(i, 1, n){
            hash[i] = (hash[i-1]*r + (str[i]))%mod;
            power[i] = (power[i-1]*r)%mod;
        }
    }
    ll calHash(ll l, ll r){
        return (((hash[r] - hash[l])*power[r-l])%mod + mod)%mod;
    }
    int distinctEchoSubstrings(string text) {
        ll n = text.size();
        rolling_hash(text, n);
        set<ll> st;
        for(ll len=1;len<=n/2;len++){
            ll count = 0;
            for(ll i=0,j=len;j<n;i++,j++){
                if(text[i] == text[j])count++;
                else count = 0;

                if(count == len){
                    st.insert(calHash(i, j));
                    count--;
                }
            }
        }
        return st.size();
    }
};