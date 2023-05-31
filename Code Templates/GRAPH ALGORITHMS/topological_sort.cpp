int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;

void dfs(int node) {
    vis[node] = true;
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it);
    }

    ans.push_back(node);
}

void topological_sort() {
    vis.assign(n, false);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end());
}