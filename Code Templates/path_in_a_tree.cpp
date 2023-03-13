bool dfs(int node, int par, vector<int> adj, vector<int> &ds, int target) {
    ds.push_back(node);
    if(node == target) {
        return true;
    }

    for(auto it : adj[node]) {
        if(node == par) continue;
        if(dfs(it, node, adj, ds, target)) {
            return true;
        }
    }

    ds.pop_back();
    return false;
}