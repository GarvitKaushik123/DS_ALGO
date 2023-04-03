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
 

void solve(){
    ll n;cin>>n;
    vector<string> arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    map<char, set<char>> graph;
    set<char> ispresent;

    for(ll i=0;i<n-1;i++){
        string s1 = arr[i];
        string s2 = arr[i+1];
        for(ll j=0;j<min(s1.size(), s2.size());j++){
            char c1 = s1[j];
            char c2 = s2[j];
            if(c1 == c2)continue;
            graph[c1].insert(c2);
            ispresent.insert(c1);
            ispresent.insert(c2);
            break;
        }
    }

    // map<char, ll> indegree;
    vector<ll> indegree(26, 0);
    for(auto e: ispresent){
        for(auto c: graph[e])indegree[c-'a']++;
    }

    queue<char>q;
    for(auto e: ispresent){
        if(indegree[e-'a'] == 0)q.push(e);
    }
    string ans="";
    while(!q.empty()){
        auto rem = q.front();
        q.pop();
        ans+=rem;
        for(auto e: graph[rem]){
            indegree[e-'a']--;
            if(indegree[e-'a'] == 0)q.push(e);
        }
    }
    for(auto s: arr){
        for(auto e: s){
            if(ispresent.find(e) == ispresent.end())ans+=e;
        }
    }

    cout<<ans<<endl;
}
int main()
{
 fast_cin();
 ll t=1;
 for(int it=1;it<=t;it++) {
     solve();
 }
 return 0;
};