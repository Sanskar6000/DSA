#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define dbg(x...)
#endif
   int n, m;
vector<int> vis, color;
 
bool dfs(int node, vector<int> adj[]) {
    if(color[node] == 0) color[node] = 1;

    for(auto it : adj[node]) {
        if(color[it] == 0) {
            color[it] = color[node] ^ 3;

            if(!dfs(it, adj)) return false;
        }
        else if(color[it] == color[node]) return false;
    }
    return true;
}
 
bool color_all(vector<int> adj[]) {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(!dfs(i, adj)) {
                return false;
            }
        }
    }
 
    return true;
}
 
void solve() {
 
    cin >> n >> m;
    vis.resize(n + 1);
    color.resize(n + 1);
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(color_all(adj)) {
        for(int i = 1; i <= n; i++) cout << color[i] << ' ';
    }
    else cout << "IMPOSSIBLE";
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}