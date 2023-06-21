//Edge when removed graph breaks into different components
//time[] -> Time at insertion of DFS
//low[] -> min Lowest time of insertion of all adjacent nodes apart from parent
#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> time, low, vis;
vector<vector<int>> ans;
int timer = 1;

void dfs(int node, int parent) {
    vis[node] = 1;
    time[node] = low[node] = timer;
    timer++;

    for(auto it : adj[node]) {
        if(it == parent) continue;
        if(!vis[it]) {
            dfs(it, node);
            low[node] = min(low[node], low[it]);
            if(low[it] > time[node]) {
                ans.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}

void solve() {
    time.resize(n);
    low.resize(n);
    vis.resize(n);
    dfs(0, -1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}