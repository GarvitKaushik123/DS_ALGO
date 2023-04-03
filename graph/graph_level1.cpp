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
    for(ll i=0;i<arr.size();i++)
    {
        cout<<arr[i];
        if(i!=arr.size()-1)cout<<" ";
    }
}
 
// bool hasPath(ll src, ll dest, vector<vector<pair<ll, ll>>> &graph, vector<bool>& vis){
//     if(vis[src])return false;
//     if(src == dest)return true;
//     vis[src] = true;
//     for(ll i=0;i<graph[src].size();i++){
//         ll nbr = graph[src][i].second;
//         if(hasPath(nbr, dest, graph, vis))return true;
//     }
//     return false;
// }

// void printAllPaths(ll src, ll dest, vector<vector<pair<ll, ll>>> &graph, vector<bool>& vis, vector<ll>& asf){
//     if(vis[src])return;
//     if(src == dest){
//         print(asf);
//         cout<<endl;
//         return;
//     }
//     vis[src] = true;
//     for(ll i=0;i<graph[src].size();i++){
//         ll nbr = graph[src][i].second;
//         asf.push_back(nbr);
//         printAllPaths(nbr, dest, graph, vis, asf);
//         asf.pop_back();
//     }
//     vis[src] = false;
// }

// ll largest = INT_MIN;
// ll smallest = INT_MAX;
// ll d_ceil = INT_MAX;
// ll d_floor = INT_MIN;

// vector<ll> ans_largest;
// vector<ll> ans_smallest;
// vector<ll> ans_dceil;
// vector<ll> ans_dfloor;

// void multisolver(ll src, ll dest, vector<vector<pair<ll, ll>>> &graph, vector<bool>& vis, vector<ll>& asf, ll wt, ll& k, ll& d, priority_queue<pair<ll,vector<ll>>, vector<pair<ll,vector<ll>>>, greater<pair<ll,vector<ll>>>>& pq){
//     if(vis[src])return;
//     if(src == dest){
//         if(wt<smallest){
//             smallest = wt;
//             ans_smallest = asf;
//         }
//         if(wt>largest){
//             largest = wt;
//             ans_largest = asf;
//         }
//         if(wt>d and wt<d_ceil){
//             d_ceil = wt;
//             ans_dceil = asf;
//         }
//         if(wt<d and wt>d_floor){
//             d_floor = wt;
//             ans_dfloor = asf;
//         }
//         if(pq.size()<k){
//             pq.push({wt, asf});
//         }else if(pq.size() == k and pq.top().first<wt){
//             pq.pop();
//             pq.push({wt, asf});
//         }
//         return;
//     }
//     vis[src] = true;
//     for(ll i=0;i<graph[src].size();i++){
//         ll nbr = graph[src][i].second;
//         asf.push_back(nbr);
//         multisolver(nbr, dest, graph, vis, asf, wt + graph[src][i].first, k, d, pq);
//         asf.pop_back();
//     }
//     vis[src] = false;
//     // ll src;cin>>src;
//     // ll dest;cin>>dest;
//     // ll d;cin>>d;
//     // ll k;cin>>k;
//     // vector<bool> vis(n, false);
//     // vector<ll> asf;
//     // asf.push_back(src);
//     // // printAllPaths(src, dest, graph, vis, asf);
//     // priority_queue<pair<ll,vector<ll>>, vector<pair<ll,vector<ll>>>, greater<pair<ll,vector<ll>>>> pq;
//     // multisolver(src, dest, graph, vis, asf, 0, k, d, pq);
//     // cout<<"Smallest Path = ";
//     // print(ans_smallest);
//     // cout<<"@"<<smallest<<endl;
//     // cout<<"Largest Path = ";
//     // print(ans_largest);
//     // cout<<"@"<<largest<<endl;
//     // cout<<"Just Larger Path than "<<d<<" = ";
//     // print(ans_dceil);
//     // cout<<"@"<<d_ceil<<endl;
//     // cout<<"Just Smaller Path than "<<d<<" = ";
//     // print(ans_dfloor);
//     // cout<<"@"<<d_floor<<endl;
//     // cout<<k<<"th largest path = ";
//     // vector<ll>ans_k = pq.top().second;
//     // print(ans_k);
//     // cout<<"@"<<pq.top().first<<endl;
// }

// // vector<ll> con_comp(ll src, vector<bool>& vis, vector<vector<pair<ll, ll>>>& graph){
// //     if(vis[src])return {};
// //     vis[src] = true;
// //     vector<ll> ans;
// //     ans.push_back(src);
// //     for(ll i=0;i<graph[src].size();i++){
// //         ll nbr = graph[src][i].second;
// //         vector<ll> t_a = con_comp(nbr, vis, graph);
// //         for(auto nbrs: t_a)ans.push_back(nbrs);
// //     }
// //     return ans;
// //         vector<vector<ll>> ans;
// //     vector<bool> vis(n, false);
// //     for(ll i=0;i<n;i++){
// //         if(!vis[i]){
// //             vector<ll> x = con_comp(i, vis, graph);
// //             ans.push_back(x);
// //             // print(x);
// //         }
// //     }

// //     // cout<<"[";
// //     // for(ll i=0;i<ans.size();i++){
// //     //     cout<<"[";
// //     //     print(ans[i]);
// //     //     cout<<"]";
// //     //     if(i != ans.size()-1)cout<<", ";
// //     // }
// //     // cout<<"]"<<endl;
// // }

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

// // void connect_islands(ll x, ll y, ll&n, ll&m,  vector<vector<bool>> &vis, vector<vector<ll>> &graph){
// //     vector<ll> dx = {0, 0, 1, -1};
// //     vector<ll> dy = {1, -1, 0, 0};
// //     if(vis[x][y] || graph[x][y] == 1)return;
// //     vis[x][y] = true;
// //     for(ll i=0;i<4;i++){
// //         ll nx = x + dx[i];
// //         ll ny = y + dy[i];
// //         if(nx>=0 and ny>=0 and nx<n and ny<m  and vis[nx][ny]==false and graph[nx][ny] == 0)connect(nx, ny, n, m, vis, graph);
// //     }
// // }

// ll count_members(ll src, vector<bool>& vis, vector<vector<ll>>& graph){
//     if(vis[src])return 0;
//     vis[src] = true;
//     ll ans = 1;
//     for(ll i=0;i<graph[src].size();i++){
//         ll nbr = graph[src][i];
//         ans += count_members(nbr, vis, graph);
//     }
//     return ans;
//     //     vector<bool> vis(n, false);
//     // vector<ll> ans;
//     // for(ll i=0;i<n;i++){
//     //     if(vis[i] == false){
//     //         ll cnt = count_members(i, vis, graph);
//     //         ans.push_back(cnt);
//     //     }
//     // }
//     // ll answer = 0;
//     // for(ll i=0;i<ans.size();i++){
//     //     for(ll j=i+1;j<ans.size();j++){
//     //         answer+=ans[i]*ans[j];
//     //     }
//     // }
//     // cout<<answer<<endl;
// }

// void hamiltonian_dfs(ll curr, ll& src, ll &n, ll nc, string asf, vector<bool>& vis, vector<vector<pair<ll,ll>>>& graph, vector<string>& ham_path, vector<string>& ham_cycle){
//     if(vis[curr])return;
//     if(nc+1 == n){
//         vis[curr] = true;
//         // check for cycle
//         bool isCycle = false;
//         for(ll i=0;i<graph[curr].size();i++){
//             if(graph[curr][i].second == src){
//                 isCycle = true;
//                 break;
//             }
//         }

//         string x = asf+to_string(curr);
//         if(isCycle)ham_cycle.push_back(x);
//         else ham_path.push_back(x);
//         vis[curr] = false;
//         return;
//     }

//     vis[curr] = true;
//     string x = asf+to_string(curr);
//     for(ll i=0;i<graph[curr].size();i++){
//         ll nbr = graph[curr][i].second;
//         hamiltonian_dfs(nbr, src, n, nc+1, x, vis, graph, ham_path, ham_cycle);
//     }
//     vis[curr] = false;
// }

// void hamiltonian(){
//     ll n;cin>>n;
//     ll e;cin>>e;
//     vector<vector<pair<ll,ll>>> graph(n);
//     for(ll i=0;i<e;i++){
//         ll start;cin>>start;
//         ll end;cin>>end;
//         ll path;cin>>path;
//         graph[start].push_back({path, end});
//         graph[end].push_back({path, start});
//     }
//     ll src;cin>>src;
//     vector<bool> vis(n, false);
//     vector<string> ham_path, ham_cycle;
//     ll x = 0;
//     hamiltonian_dfs(src, src, n, x, "", vis, graph, ham_path, ham_cycle);
//     for(auto s: ham_path){
//         cout<<s<<"."<<endl;
//     }
//     for(auto s: ham_cycle){
//         cout<<s<<"*"<<endl;
//     }
// }

// void knightstour_dfs(ll r, ll c, ll step, ll& n, vector<vector<ll>> &vis){
//     vector<ll> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
//     vector<ll> dy = {1, 2, 2, 1, -1, -2, -2, -1};
//     if(r<0 or c<0 or r>=n or c>=n or vis[r][c] != 0)return;
//     vis[r][c] = step;
//     if(step == n*n){
//         for(ll i=0;i<n;i++){
//             print(vis[i]);
//             cout<<endl;
//         }
//         cout<<endl;
//         vis[r][c] = 0;
//         return;
//     }

//     for(ll i=0;i<8;i++){
//         ll nx = r + dx[i];
//         ll ny = c + dy[i];
//         knightstour_dfs(nx, ny, step+1, n, vis);
//     }
//     vis[r][c] = 0;
// }

// void knightstour(){
//     ll n;cin>>n;
//     ll r;cin>>r;
//     ll c;cin>>c;

//     vector<vector<ll>> vis(n, vector<ll>(n, 0));
//     knightstour_dfs(r, c, 1, n, vis);
// }


// void bfs(){
//     ll n;cin>>n;
//     ll e;cin>>e;
//     vector<vector<pair<ll,ll>>> graph(n);
//     for(ll i=0;i<e;i++){
//         ll start;cin>>start;
//         ll end;cin>>end;
//         ll path;cin>>path;
//         graph[start].push_back({path, end});
//         graph[end].push_back({path, start});
//     }
//     ll src;cin>>src;
//     vector<bool> vis(n, false);
//     queue<pair<ll, string>> q;
//     string x = to_string(src);
//     q.push({src, x});
//     while(!q.empty()){
//         auto temp = q.front();
//         q.pop();
//         ll curr = temp.first;
//         string asf = temp.second;
//         if(vis[curr])continue;
//         vis[curr]=true;
//         cout<<curr<<"@"<<asf<<endl;
//         for(ll i=0;i<graph[curr].size();i++){
//             ll nbr = graph[curr][i].second;
//             if(vis[nbr] == true)continue;
//             string x = asf + to_string(nbr);
//             q.push({nbr, x});
//         }
//     }
// }

// bool isBipartite(){
//     ll n;cin>>n;
//     ll e;cin>>e;
//     vector<vector<pair<ll,ll>>> graph(n);
//     for(ll i=0;i<e;i++){
//         ll start;cin>>start;
//         ll end;cin>>end;
//         ll path;cin>>path;
//         graph[start].push_back({path, end});
//         graph[end].push_back({path, start});
//     }
//     vector<ll> vis(n, -1);
//     queue<pair<ll,ll>> q;
//     for(ll i=0;i<n;i++){
//         if(vis[i]==-1){
//             q.push({i, 0});
//             while(!q.empty()){
//                 auto rem = q.front();
//                 q.pop();
//                 if(vis[rem.first] != -1){
//                     if(rem.second != vis[rem.first])return false;
//                     continue;
//                 }
//                 vis[rem.first] = rem.second;
//                 for(ll i=0;i<graph[rem.first].size();i++){
//                     ll nbr = graph[rem.first][i].second;
//                     if(vis[nbr] == -1)q.push({nbr, ((rem.second)+1)%2});
//                 }
//             }
//         }
//     }
//     return true;
// }

// void spreadInfection(){
//     ll n;cin>>n;
//     ll e;cin>>e;
//     vector<vector<pair<ll,ll>>> graph(n);
//     for(ll i=0;i<e;i++){
//         ll start;cin>>start;
//         ll end;cin>>end;
//         ll path;cin>>path;
//         graph[start].push_back({path, end});
//         graph[end].push_back({path, start});
//     }
//     ll person;cin>>person;
//     ll t;cin>>t;
//     vector<bool> vis(n, false);
//     queue<ll> q;
//     ll count = 1;
//     q.push(person);
//     ll ans = 0;
//     while(count<=t){
//         ll size = q.size();
//         ans+=size;
//         while(size--){
//             auto rem = q.front();
//             q.pop();
//             if(vis[rem])continue;
//             vis[rem] = true;
//             for(ll i=0;i<graph[rem].size();i++){
//                 ll nbr = graph[rem][i].second;
//                 if(!vis[nbr])q.push(nbr);
//             }
//         }
//         count++;
//     } 
//     cout<<ans-1<<endl;
// }


// // void dijsktra(){
// //     ll n;cin>>n;
// //     ll e;cin>>e;
// //     vector<vector<pair<ll,ll>>> graph(n);
// //     for(ll i=0;i<e;i++){
// //         ll start;cin>>start;
// //         ll end;cin>>end;
// //         ll path;cin>>path;
// //         graph[start].push_back({path, end});
// //         graph[end].push_back({path, start});
// //     }
// //     ll src;cin>>src;
// //     vector<bool> vis(n, false);
// //     priority_queue<unit, vector<unit>, cmp> pq;
// //     pq.push(unit(src, 0, to_string(0)));
// //     while(!pq.empty()){
// //         auto rem = pq.top();
// //         pq.pop();
// //         if(vis[rem.val])continue;
// //         cout<<rem.val<<" via "<<rem.asf<<" @ "<<rem.wt<<endl;
// //         vis[rem.val] = true;
// //         for(ll i=0;i<graph[rem.val].size();i++){
// //             ll nbr = graph[rem.val][i].second;
// //             if(!vis[nbr])pq.push(unit(nbr, rem.wt+graph[rem.val][i].first, rem.asf+to_string(nbr)));
// //         }
// //     }    
// // }

// class unit{
//     public:
//         ll val;
//         ll wt;
//         ll av;
    
//     unit(ll val, ll wt, ll av){
//         this->val = val;
//         this->wt = wt;
//         this->av = av;
//     }
// };

// struct cmp{
//     bool operator()(unit a, unit b){
//         if(a.wt>b.wt)return true;
//         else return false;
//     }
// };

// void prims(){
//     ll n;cin>>n;
//     ll e;cin>>e;
//     vector<vector<pair<ll,ll>>> graph(n);
//     for(ll i=0;i<e;i++){
//         ll start;cin>>start;
//         ll end;cin>>end;
//         ll path;cin>>path;
//         graph[start].push_back({path, end});
//         graph[end].push_back({path, start});
//     } 
//     vector<bool> vis(n, false);
//     priority_queue<unit, vector<unit>, cmp> pq;
//     pq.push(unit(0, 0, -1));
//     while(!pq.empty()){
//         auto rem = pq.top();
//         pq.pop();
//         if(vis[rem.val])continue;
//         if(rem.av!=-1)cout<<"["<<rem.val<<"-"<<rem.av<<"@"<<rem.wt<<"]"<<endl;
//         vis[rem.val] = true;
//         for(ll i=0;i<graph[rem.val].size();i++){
//             ll nbr = graph[rem.val][i].second;
//             if(!vis[nbr])pq.push(unit(nbr, graph[rem.val][i].first, rem.val));
//         }
//     }     
// }

void top_sort_dfs(ll src, stack<ll>& st, vector<bool>& vis, vector<vector<ll>>& graph){
    if(vis[src])return;
    vis[src] = true;
    for(ll i=0;i<graph[src].size();i++){
        ll nbr = graph[src][i];
        top_sort_dfs(nbr, st, vis, graph);
    }
    st.push(src);
}

void top_sort(){
    ll n;cin>>n;
    ll e;cin>>e;
    vector<vector<ll>> graph(n);
    for(ll i=0;i<e;i++){
        ll start;cin>>start;
        ll end;cin>>end;
        graph[start].push_back(end);
    } 
    vector<bool> vis(n, false);
    stack<ll> st;
    for(ll i=0;i<n;i++){
        if(vis[i]==false){
            top_sort_dfs(i, st, vis, graph);
        }
    }
    while(!st.empty()){
        auto e = st.top();
        st.pop();
        cout<<e<<endl;
    }
}

void iterative_dfs(){
    ll n;cin>>n;
    ll e;cin>>e;
    vector<vector<pair<ll,ll>>> graph(n);
    for(ll i=0;i<e;i++){
        ll start;cin>>start;
        ll end;cin>>end;
        ll path;cin>>path;
        graph[start].push_back({path, end});
        graph[end].push_back({path, start});
    } 
    vector<bool> vis(n, false);
    ll src;cin>>src;
    stack<pair<ll, string>> st;
    st.push({src, to_string(src)});
    while(!st.empty()){
        auto rem = st.top();
        st.pop();
        if(vis[rem.first])continue;
        vis[rem.first] = true;
        cout<<rem.first<<"@"<<rem.second<<endl;
        for(ll i=0;i<graph[rem.first].size();i++){
            ll nbr = graph[rem.first][i].second;
            if(!vis[nbr])st.push({nbr, rem.second + to_string(nbr)});
        }
    }
}

int main()
{
 fast_cin();
 ll t=1;
//  cin >> t;
 for(int it=1;it<=t;it++) {
    iterative_dfs();
 }
 return 0;
}