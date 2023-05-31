void dfs(int node, int par, vector<int> adj[]) {
    cout << node << ' ';
    for(auto it : adj[node]) {
        if(it == par) continue;
        dfs(it, node, adj);
    }
}

int dfs(int node, int par, vector<int> adj[]) {
    int sum = 0;
    for(auto it : adj[node]) {
        if(it == par) continue;
        sum += dfs(it, node, adj) + 1;
    }

    return sum;
}

//graphs
vector<int> vis(n + 1, 0);
void dfs(int node, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj);
        }
    }
    //Backtracking
    // vis[node] = 0;
}

for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
        dfs(i, vis, adj);
    }
}