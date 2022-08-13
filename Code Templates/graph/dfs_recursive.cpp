 void dfs(vector<int> &vis, vector<int> adj[], int source) {
        vis[source] = 1;
        for(auto i : adj[source]) {
            if(!vis[i]) {
                dfs(vis, adj, i);
            }
        }
    }